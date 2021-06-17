#include "term.h"

/*Some screen standards*/
static const size_t   SCREEN_WIDTH    = 80;
static const size_t   SCREEN_HEIGHT   = 25;
static const uint8_t  STD_COLOR       = 7; /*grey foreground with black background*/

/*Position of the cursor*/
size_t cursor_x;
size_t cursor_y;

/*The terminal buffer*/
uint16_t* buffer;

static inline uint16_t screen_char (char c) {
    return (uint16_t) c | (uint16_t) STD_COLOR << 8;
}

void term_enable_cursor(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x0A, 0x3D4);
	outb((inb(0x3D5) & 0xC0) | cursor_start, 0x3D5);
 
	outb(0x0B, 0x3D4);
	outb((inb(0x3D5) & 0xE0) | cursor_end, 0x3D5);
}

void update_cursor()
{
	uint16_t pos = cursor_y * SCREEN_WIDTH + cursor_x;
 
	outb(0x0F, 0x3D4);
	outb((uint8_t) (pos & 0xFF), 0x3D5);
	outb(0x0E, 0x3D4);
	outb((uint8_t) ((pos >> 8) & 0xFF), 0x3D5);
}

void term_clear() {
    buffer = (uint16_t*) 0xB8000;
    for (size_t y = 0; y < SCREEN_HEIGHT; y++) {
        for (size_t x = 0; x < SCREEN_WIDTH; x++) {
            const size_t index = y * SCREEN_WIDTH + x;
            /*Put the ' ' in every char*/
            buffer[index] = screen_char(' ');
        }
    }
}

void end_of_screen() {
    cursor_y = 0;
}

void new_line() {
    cursor_x = 0;
    cursor_y++;
    if(cursor_y >= SCREEN_HEIGHT)
        end_of_screen();
}

void write_char_screen (char c) {
    /*New line control*/
    if(c == '\n') {
        new_line();
        return;
    }

    const size_t index = cursor_y * SCREEN_WIDTH + cursor_x;
    buffer[index] = screen_char(c);
    cursor_x++;
    if(cursor_x >= SCREEN_WIDTH) {
        cursor_x = 0;
        cursor_y++;
        if(cursor_y >= SCREEN_HEIGHT)
            end_of_screen();
    }
}


size_t strlen(const char* str) {
    size_t length = 0;
    while (str[length])
        length++;
    return length;
}

void term_write_string(const char* str) {
    for(size_t i = 0; i < strlen(str); i++)
        write_char_screen(str[i]);
    update_cursor();
}
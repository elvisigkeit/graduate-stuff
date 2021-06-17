#ifndef TERM_H
#define TERM_H

#include <stdint.h>
#include <stddef.h>
#include <sys/io.h>

void term_clear();
void term_enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
void term_write_string(const char* str);

#endif
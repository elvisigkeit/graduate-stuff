#include "../term/term.h"

int kernel_main() {
    term_write_string("Bem vindo!\n:D");
}

int init_so(void* multiboot_structure, uint32_t magicnumber) {
    /*Should configure everything*/
    term_clear();
    term_enable_cursor(13, 14); /*configures the cursor, first the beggining line to ending line, all vertical.*/

    /*And call kernel_main*/
    kernel_main();
}
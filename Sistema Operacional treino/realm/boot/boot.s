/*Declaring the multiboot header global variables*/
.set ALIGN,     1<<0                        /*align loaded modules in pages*/
.set MEMINFO,   1<<1                        /*provide memory map*/
.set FLAGS,     ALIGN | MEMINFO             /*the union of flags for multiboot*/
.set MAGIC,     0x1BADB002                  /*number to certify it is a multiboot*/
.set CHECKSUM,  -(MAGIC + FLAGS)            /*the checksum to verify the variables*/

/*Declaring the multiboot header*/
.section    .multiboot
.align      4
.long       MAGIC
.long       FLAGS
.long       CHECKSUM

/*The kernel stack*/
.section    .bss
.align      16
stack_bottom:
.skip       0x4000
stack_top:

/*The boot code*/
.section    .text
.global     _start
.type       _start, @function
_start:
    /*configuring the stack pointer*/
    mov $stack_top, %esp

    /*starting the kernel*/
    call init_so

    /*if the kernel returns, maintain the system running*/
    cli
1:  hlt
    jmp 1b

/*
setting the size of _start function for debuging
all tutorials do, I do too
*/
.size   _start, . - _start

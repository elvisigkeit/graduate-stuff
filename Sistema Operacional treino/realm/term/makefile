GPPPARAMS = -m32 -O2 -nostdlib -fno-builtin -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

all: term.o

term.o: term.c
	gcc $(GPPPARAMS) -o ../build/$@ -c $<

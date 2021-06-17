GPPPARAMS = -m32 -O2 -nostdlib -fno-builtin -fno-leading-underscore
ASPARAMS = --32
LDPARAMS = -melf_i386

all: boot.o kernel.o

kernel.o: kernel.c
	gcc $(GPPPARAMS) -o ../build/$@ -c $<

boot.o: boot.s
	as $(ASPARAMS) -o ../build/$@ $<
	
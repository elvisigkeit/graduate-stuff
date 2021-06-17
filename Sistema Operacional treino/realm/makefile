all:
	+$(MAKE) -C boot
	+$(MAKE) -C term

objects = $(wildcard build/*.o)

kernel.bin: linker.ld all
	ld $(LDPARAMS) -T $< -o build/$@ $(objects)

kernel.iso: kernel.bin
	mkdir -p iso/boot/grub
	cp build/$< iso/boot/
	echo 'set timeout-0' >> iso/boot/grub/grub.cfg
	echo 'set default-0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "realm"{' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=build/$@ iso
	rm -rf iso

run: kernel.iso
	qemu-system-i386 -cdrom build/$<

clean:
	rm build/*

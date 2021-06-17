build:
	gcc -o nuke-rm main.c nuke-rm.c

pre-test:
	@mkdir -p test/A/B/C
	@echo "Hello world" > test/A/B/C/hello.txt
	@echo "Foo" > test/A/B/bar.txt
	@dd if=/dev/zero of=test/example.log bs=1M count=100

test: build pre-test
	./nuke-rm -n 3 -r ./test

.PHONY: build pre-test test

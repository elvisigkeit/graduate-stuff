CC=gcc
RM=rm 
SRCS=main_teste.c

all: tela

tela:
	@$(CC) -o main $(SRCS) `pkg-config --cflags --libs gtk+-3.0 gladeui-2.0`

run: tela
	@./main

clean:
	@$(RM) main
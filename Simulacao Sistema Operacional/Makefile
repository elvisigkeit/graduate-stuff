CC=gcc
RM=rm 
SRCS=sim.c escalonador.c listaio.c processo.c memoria.c

all: simulador

simulador:
	@$(CC) -o main $(SRCS)

run: simulador
	@./main

clean:
	@$(RM) main
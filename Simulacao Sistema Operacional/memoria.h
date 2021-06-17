#ifndef MEMORIA_H
#define MEMORIA_H

#define WSL 4
#include "listaio.h"
#include "processo.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct lista_swap lista_swap;
struct lista_swap {
    unsigned id;
    unsigned paginas;
    lista_swap* prox;
};

void acesso_a_memoria(processo, unsigned, unsigned);
void configura_memoria();
void limpa_memoria();
#endif
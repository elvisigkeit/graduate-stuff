#include <stdio.h>
#include <stdlib.h>
#include "listaio.h"

unsigned randm(unsigned div) { return (rand() % div); }
char randb() { return (rand() % 2); }

void rm_primeiro_io(lista_io** lista) {
    lista_io* removido = *lista;
    *lista = (*lista)->prox;
    free(removido);
}

void limpa_lista_io(lista_io** ios) {
    while(*ios) 
        rm_primeiro_io(ios);
}

void copia_lista_io(lista_io* origem, lista_io** destino) {
    if(!origem)
        return;

    *destino = (lista_io*) calloc(1, sizeof(lista_io));
    (**destino).instante = origem->instante; (**destino).tipo = origem->tipo;
    (**destino).duracao = origem->duracao;
    copia_lista_io(origem->prox, &((**destino).prox));
}

void adc_io_ordenado(lista_io** lista, unsigned instante, char tipo) {
    lista_io* continuacao = NULL;
    lista_io* novo = (lista_io*) calloc(1, sizeof(lista_io));
    
    while(*lista) {
        if((**lista).instante > instante) {
            continuacao = *lista;
            break;
        }
        lista = &((*lista)->prox);
    }

    *lista = novo;
    int duracao = randm(MAX_DUR_IO)+1;
    switch(randm(3)) {
        case 0:
            (**lista).duracao = duracao*MUL_DISCO;
        break;
        case 1:
            (**lista).duracao = duracao*MUL_FITA;
        break;
        case 2:
            (**lista).duracao = duracao*MUL_IMPRESSORA;
        break;
    }
    (**lista).instante = instante; (**lista).tipo = tipo;
    (**lista).prox = continuacao;
}

void adc_io(lista_io** lista, unsigned instante, char tipo) {
    while(*lista) {
        lista = &((*lista)->prox);
    }

    *lista = (lista_io*) calloc(1, sizeof(lista_io));
    (**lista).instante = instante; (**lista).tipo = tipo;
    (**lista).prox = NULL;
}

void descreve_io(lista_io* io) {
    printf("     ");
    switch(io->tipo){
        case _DISCO:
            printf("Disco     ");
        break;
        case _FITA:
            printf("Fita      ");
        break;
        case _IMPRESSORA:
            printf("Impressora");
        break;
        default:
        break;
    }
    printf("\n     - Inst: %2i", io->instante);
    printf("\n     - Dura: %2i\n", io->duracao);
}
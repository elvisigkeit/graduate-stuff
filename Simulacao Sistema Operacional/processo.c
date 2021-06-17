#include <stdio.h>
#include <stdlib.h>
#include "listaio.h"
#include "processo.h"

void rm_primeiro_proc(lista_proc** lista) {
    lista_proc* removido = *lista;
    *lista = (*lista)->prox;

    removido->ponteiros--;
    if(removido->ponteiros == 0) {
        lista_io* ios = removido->atual.io;
        while(ios){
            lista_io* io_removido = ios;
            ios = ios->prox;
            free(io_removido);      
        }
        free(removido);
    }
}

void limpa_lista_proc(lista_proc** processos) {
    while(*processos) 
        rm_primeiro_proc(processos);
}

void adc_proc_por_chegada(lista_proc** lista, unsigned id, unsigned chegada, unsigned duracao, char prioridade) {
    lista_proc* continuacao = NULL;
    lista_proc* novo = (lista_proc*) calloc(1, sizeof(lista_proc));
    
    while(*lista) {
        if((**lista).atual.chegada > chegada) {
            continuacao = *lista;
            break;
        }
        lista = &((*lista)->prox);
    }

    *lista = novo;
    ((**lista).atual).id = id; ((**lista).atual).chegada = chegada; (**lista).ponteiros = 1; 
    ((**lista).atual).duracao = duracao; ((**lista).atual).io = NULL;  ((**lista).atual).executado = 0; 
    ((**lista).atual).pri = prioridade; ((**lista).atual).retorno_io = -1;
    (**lista).prox = continuacao;
}

void adc_proc_por_retorno(lista_proc** lista, unsigned id, unsigned chegada, unsigned retorno, unsigned executado, unsigned duracao, char prioridade, lista_io* ios) {
    lista_proc* continuacao = NULL;
    lista_proc* novo = (lista_proc*) calloc(1, sizeof(lista_proc));
    
    while(*lista) {
        if((**lista).atual.retorno_io > retorno) {
            continuacao = *lista;
            break;
        }
        lista = &((*lista)->prox);
    }

    *lista = novo;
    ((**lista).atual).id = id; ((**lista).atual).chegada = chegada; (**lista).ponteiros = 1; ((**lista).atual).executado = executado; 
    ((**lista).atual).duracao = duracao; ((**lista).atual).pri = prioridade; ((**lista).atual).retorno_io = retorno;
    copia_lista_io(ios, &(((**lista).atual).io));
    (**lista).prox = continuacao;
}

void adc_proc(lista_proc** lista, unsigned id, unsigned chegada, unsigned retorno, unsigned executado, unsigned duracao, char prioridade, lista_io* ios) {
    while(*lista) {
        lista = &((*lista)->prox);
    }

    *lista = (lista_proc*) calloc(1, sizeof(lista_proc));
    ((**lista).atual).id = id; ((**lista).atual).chegada = chegada; (**lista).ponteiros = 1; 
    ((**lista).atual).duracao = duracao;((**lista).atual).executado = executado; 
    ((**lista).atual).pri = prioridade; ((**lista).atual).retorno_io = retorno;
    copia_lista_io(ios, &(((**lista).atual).io));
}

void adc_proc_copia(lista_proc** lista, lista_proc* proc) {
    while(*lista) {
        lista = &((*lista)->prox);
    }

    *lista = proc; proc->ponteiros++;
    proc->prox = NULL;
}

void descreve_processo(processo proc) {
    printf("+ Processo:%2u\tChegada: %3i\tDuração: %2i\n", proc.id, proc.chegada, proc.duracao);
    lista_io* ios = proc.io;
    if (ios)
        printf("   Chamadas de IO:\n");
    else
        printf("   Sem chamadas de IO.\n");
    while(ios) {
        descreve_io(ios);
        ios = ios->prox;
    }
}

void descreve_processos(lista_proc* processos) {
    lista_proc* printaveis = processos;
    while(printaveis) {
        descreve_processo(printaveis->atual);
        printaveis = printaveis->prox;
    }
}
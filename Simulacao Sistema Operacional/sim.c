#include <stdio.h>
#include <stdlib.h>
#include "listaio.h"
#include "processo.h"
#include "escalonador.h"
#include "memoria.h"

#define D_MAX   24
#define C_MAX   20

void adc_io_aleatoriamente(lista_proc* processos, unsigned nr_ios) {
    lista_proc* aux;
    while(nr_ios > 0) {
        aux = processos;

        while(aux->prox && randb())
            aux = aux->prox;

        adc_io_ordenado(&((aux->atual).io), randm((aux->atual).duracao), _DISCO);

        nr_ios--;
    }
}

void simulacao(lista_proc** processos) {
    printf("\nInicia-se a simulação...\n\n");
    rrobin(processos, 4);
}

void agenda_compassada(lista_proc** processos, unsigned nr_processos) {
    unsigned i;
    srand(0);

    adc_proc_por_chegada(processos, 1, 3, randm(D_MAX)+6, randb());
    for(i=2; i<nr_processos+1; i++) 
        adc_proc_por_chegada(processos, i, i*3, randm(D_MAX)+6, randb());
    adc_io_aleatoriamente(*processos, nr_processos/2);
    descreve_processos(*processos);
}

void agenda_aleatoria(lista_proc** processos, unsigned nr_processos) {
    unsigned i;
    srand(0);

    adc_proc_por_chegada(processos, 0, 0, randm(D_MAX), randb());
    for(i=1; i<nr_processos; i++) 
        adc_proc_por_chegada(processos, i, randm(C_MAX), randm(D_MAX)+1, randb());
    adc_io_aleatoriamente(*processos, nr_processos/2);

    descreve_processos(*processos);
}

void agenda(lista_proc** processos) {
    adc_proc_por_chegada(processos, 1, 0, 5, 1);
    adc_io_ordenado(&((*processos)->atual.io), 2, _DISCO);
    adc_io_ordenado(&((*processos)->atual.io), 3, _FITA);
    adc_proc_por_chegada(processos, 2, 3, 7, 0);
    adc_io_ordenado(&((*processos)->prox->atual.io), 4, _IMPRESSORA);
    adc_proc_por_chegada(processos, 3, 6, 10, 1);
    adc_proc_por_chegada(processos, 4, 4, 8, 1);

    descreve_processos(*processos);
}

int main () {
    lista_proc* processos = NULL;
    printf("Configuração do simulador...\n");
    printf("Processos:\n");
    configura_memoria();
    //agenda(&processos);
    //agenda_aleatoria(&processos, 4);
    agenda_compassada(&processos, 30);
    simulacao(&processos);
    limpa_lista_proc(&processos);
    limpa_memoria();
    return 0;
}
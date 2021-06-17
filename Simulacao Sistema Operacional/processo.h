#ifndef PROCESSO_H
#define PROCESSO_H

typedef struct processo processo;
struct processo {
    unsigned id;
    unsigned chegada;
    unsigned retorno_io;
    unsigned duracao;
    unsigned executado;
    char pri;
    lista_io* io;
};

typedef struct lista_proc lista_proc;
struct lista_proc {
    processo atual;
    unsigned ponteiros;
    lista_proc* prox;
};

void rm_primeiro_proc(lista_proc** lista) ;

void limpa_lista_proc(lista_proc** processos) ;

void adc_proc_por_chegada(lista_proc** lista, unsigned id, unsigned chegada, unsigned duracao, char prioridade) ;

void adc_proc_por_retorno(lista_proc** lista, unsigned id, unsigned chegada, unsigned retorno, unsigned executado, unsigned duracao, char prioridade, lista_io* ios) ;

void adc_proc(lista_proc** lista, unsigned id, unsigned chegada, unsigned retorno, unsigned executado, unsigned duracao, char prioridade, lista_io* ios) ;

void adc_proc_copia(lista_proc** lista, lista_proc* proc) ;

void descreve_processo(processo proc) ;

void descreve_processos(lista_proc* processos) ;

#endif
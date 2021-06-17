#ifndef LISTAIO_H
#define LISTAIO_H

#define MUL_DISCO       1
#define MUL_FITA        2
#define MUL_IMPRESSORA  3
#define MAX_DUR_IO      4
enum TIPO_IO { _DISCO = 16, _FITA, _IMPRESSORA};

typedef struct lista_io lista_io;
struct lista_io {
    unsigned instante;
    char tipo;
    unsigned duracao;
    lista_io* prox;
};

unsigned randm(unsigned div) ;
char randb() ;

void rm_primeiro_io(lista_io** lista) ;

void limpa_lista_io(lista_io** ios) ;

void copia_lista_io(lista_io* origem, lista_io** destino) ;

void adc_io_ordenado(lista_io** lista, unsigned instante, char tipo) ;

void adc_io(lista_io** lista, unsigned instante, char tipo) ;

void descreve_io(lista_io* io) ;
#endif
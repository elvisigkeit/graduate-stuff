#ifndef ESCALONADOR_H
#define ESCALONADOR_H

void printa_fila_espera(char C1, char C2, lista_proc* lista) ;

void printa_filas_espera(lista_proc* processos, lista_proc* fila_exec_H, lista_proc* fila_exec_L, lista_proc* fila_IO) ;

void printa_chegada_processo(processo proc) ;

void printa_retorno_processo(processo proc) ;

void chegada_processo(lista_proc** processos, lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO) ;

void retorno_processo(lista_proc** processos, lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO) ;

void executa_processo(lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO, lista_proc** processos, unsigned fatia_tempo) ;

void rrobin(lista_proc** processos, unsigned fatia_tempo) ;

#endif
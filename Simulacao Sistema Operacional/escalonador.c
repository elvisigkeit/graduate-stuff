#include <stdio.h>
#include "listaio.h"
#include "processo.h"
#include "escalonador.h"
#include "memoria.h"

unsigned tempo_global = 0;

void printa_fila_espera(char C1, char C2, lista_proc* lista) {
    printf("    %c%c[ ", C1, C2);
    while(lista) {
        printf("%2u,", lista->atual.id);
        lista = lista->prox;
    }
    printf("\b ]\n");
}

void printa_filas_espera(lista_proc* processos, lista_proc* fila_exec_H, lista_proc* fila_exec_L, lista_proc* fila_IO) {
    printf("  Filas:\n");    
    printa_fila_espera('P', ' ', processos);
    printa_fila_espera('H', ' ', fila_exec_H);
    printa_fila_espera('L', ' ', fila_exec_L);
    printa_fila_espera('I', 'O', fila_IO);
}

void printa_chegada_processo(processo proc) {
    printf("(%3i)\n  <<    Chegada    >>\n", proc.chegada);
    printf("  [%2u]  Custo: %2i\t", proc.id, proc.duracao);
    if(proc.pri)
        printf("Pri: H\n");
    else
        printf("Pri: L\n");
}

void printa_retorno_processo(processo proc) {
    printf("(%3i)\n  <<    Retorno    >>\n", proc.retorno_io);
    printf("  [%2u]  Restante: %2i\t", proc.id, (proc.duracao - proc.executado));
    if(proc.pri)
        printf("Pri: H\n");
    else
        printf("Pri: L\n");
}

void chegada_processo(lista_proc** processos, lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO) {
    if(!(*processos))
        return;

    if((**processos).atual.pri)
        adc_proc(fila_exec_H, (**processos).atual.id, (**processos).atual.chegada, (**processos).atual.retorno_io, (**processos).atual.executado, (**processos).atual.duracao, (**processos).atual.pri, (**processos).atual.io);
    else
        adc_proc(fila_exec_L, (**processos).atual.id, (**processos).atual.chegada, (**processos).atual.retorno_io, (**processos).atual.executado, (**processos).atual.duracao, (**processos).atual.pri, (**processos).atual.io);
    printa_chegada_processo((**processos).atual);
    rm_primeiro_proc(processos);
    printa_filas_espera(*processos, *fila_exec_H, *fila_exec_L, *fila_IO);
}

void retorno_processo(lista_proc** processos, lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO) {
    if(!(*fila_IO))
        return;

    if((**fila_IO).atual.pri)
        adc_proc_por_retorno(fila_exec_H, (**fila_IO).atual.id, (**fila_IO).atual.chegada, (**fila_IO).atual.retorno_io, (**fila_IO).atual.executado, (**fila_IO).atual.duracao, (**fila_IO).atual.pri, (**fila_IO).atual.io);
    else
        adc_proc_por_retorno(fila_exec_L, (**fila_IO).atual.id, (**fila_IO).atual.chegada, (**fila_IO).atual.retorno_io, (**fila_IO).atual.executado, (**fila_IO).atual.duracao, (**fila_IO).atual.pri, (**fila_IO).atual.io);
    printa_retorno_processo((**fila_IO).atual);
    rm_primeiro_proc(fila_IO);
    printa_filas_espera(*processos, *fila_exec_H, *fila_exec_L, *fila_IO);
}

void executa_processo(lista_proc** fila_exec_H, lista_proc** fila_exec_L, lista_proc** fila_IO, lista_proc** processos, unsigned fatia_tempo) {
    if(!(*fila_exec_H) && !(*fila_exec_L))
        return;

    char preempcao_io = 0;
    lista_proc* ativo = NULL;
    if(!(*fila_exec_H)) {
        ativo = *fila_exec_L;
        (*fila_exec_L)->ponteiros++;
        rm_primeiro_proc(fila_exec_L);
    } else {
        ativo = *fila_exec_H;
        (*fila_exec_H)->ponteiros++;
        rm_primeiro_proc(fila_exec_H);
    }

    printf("(%3i)\n  <<   Execução   >>\n", tempo_global);
    if(ativo->atual.io && ativo->atual.io->instante <= (ativo->atual.executado + fatia_tempo)) {
        fatia_tempo = ativo->atual.io->instante - ativo->atual.executado;
        preempcao_io = 1;
    } else {
        if((ativo->atual.duracao - ativo->atual.executado)<=fatia_tempo) 
            fatia_tempo = (ativo->atual.duracao - ativo->atual.executado);
    }
    tempo_global+=fatia_tempo; ativo->atual.executado+=fatia_tempo;
    printf("  [%2u]  Até sobrar: %2i\n", ativo->atual.id, (ativo->atual.duracao - ativo->atual.executado));
    printa_filas_espera(*processos, *fila_exec_H, *fila_exec_L, *fila_IO);

    acesso_a_memoria(ativo->atual, tempo_global, fatia_tempo);

    if(!(*fila_IO)) {
        while((*processos) && (**processos).atual.chegada <= tempo_global) 
            chegada_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
    } else {
        if (!(*processos)) {
            while((*fila_IO) && (**fila_IO).atual.retorno_io <= tempo_global) 
                retorno_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
        } else {
            while((*processos) && (*fila_IO) && ((**processos).atual.chegada <= tempo_global || (**fila_IO).atual.retorno_io <= tempo_global)) {
                if ((**processos).atual.chegada <= (**fila_IO).atual.retorno_io) {
                    chegada_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
                } else {
                    retorno_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
                }
            }
            while((*processos) && (**processos).atual.chegada <= tempo_global) 
                chegada_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
            while((*fila_IO) && (**fila_IO).atual.retorno_io <= tempo_global) 
                retorno_processo(processos, fila_exec_H, fila_exec_L, fila_IO);
        }
    }

    if(preempcao_io) {
        printf("(%3i)\n  << Preempção IO >>", tempo_global);
        ativo->ponteiros--;
        switch(ativo->atual.io->tipo){
            case _DISCO:
                printf("  [DISCO]\n");
                ativo->atual.retorno_io = tempo_global + ativo->atual.io->duracao;
                ativo->atual.pri = 0;
            break;
            case _FITA:
                printf("  [FITA]\n");
                ativo->atual.retorno_io = tempo_global + ativo->atual.io->duracao;
                ativo->atual.pri = 1;
            break;
            case _IMPRESSORA:
                printf("  [IMPRESSORA]\n");
                ativo->atual.retorno_io = tempo_global + ativo->atual.io->duracao;
                ativo->atual.pri = 1;
            break;
            default:
            break;
        }
        rm_primeiro_io(&(ativo->atual.io));
        adc_proc_copia(fila_IO, ativo);
        printf("  [%2u]  Falta: %2i\n", ativo->atual.id, (ativo->atual.duracao - ativo->atual.executado));
        printa_filas_espera(*processos, *fila_exec_H, *fila_exec_L, *fila_IO);
        return;
    }

    if((ativo->atual.duracao - ativo->atual.executado) > 0) {
        ativo->ponteiros--;
        ativo->atual.pri = 0;
        if(ativo->atual.pri)
            adc_proc_copia(fila_exec_H, ativo);
        else
            adc_proc_copia(fila_exec_L, ativo);
    } else {
        rm_primeiro_proc(&ativo);
    }
}

void rrobin(lista_proc** processos, unsigned fatia_tempo) {
    tempo_global = (**processos).atual.chegada;
    lista_proc* fila_exec_H = NULL;
    lista_proc* fila_exec_L = NULL;
    lista_proc* fila_IO = NULL;
    
    chegada_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
    while(fila_exec_H || fila_exec_L || (*processos) || fila_IO) {
        //Caso a fila esteja vazia, ele pega o primeiro entre os IOs e as chegadas
        if(!fila_exec_H && !fila_exec_L) {
            if(*processos) {
                if (fila_IO) {
                    if ((**processos).atual.chegada < (*fila_IO).atual.retorno_io) {
                        tempo_global = (**processos).atual.chegada;
                        chegada_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
                    } else {
                        tempo_global = (*fila_IO).atual.retorno_io;
                        while ((*processos) && (**processos).atual.chegada == (*fila_IO).atual.retorno_io)
                            chegada_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
                        while ((fila_IO) && (*fila_IO).atual.retorno_io == tempo_global)
                            retorno_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
                    }
                } else {
                    tempo_global = (**processos).atual.chegada;
                    chegada_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
                }
            } else {
                tempo_global = (*fila_IO).atual.retorno_io;
                while((fila_IO) && (*fila_IO).atual.retorno_io == tempo_global)
                    retorno_processo(processos, &fila_exec_H, &fila_exec_L, &fila_IO);
            }
        }

        executa_processo(&fila_exec_H, &fila_exec_L, &fila_IO, processos, fatia_tempo);
    }
    limpa_lista_proc(&fila_exec_H);
    limpa_lista_proc(&fila_exec_L);
    printf("\nFim da simulação...\n");
}
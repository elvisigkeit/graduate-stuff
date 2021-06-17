#include "memoria.h"

static unsigned lru[64];
static lista_swap* swap;
static unsigned mem_principal[64];

void mostra_memoria() {
    for (int i=0; i<8; i++) {
        printf("\n\t\t\t\t\t|");
        for (int j=0; j<8; j++) {
            unsigned val = mem_principal[i*8+j];
            if(val == 0)
                printf("\e[2m 0,\e[22m");
            else
                printf("%2i,", val);
        }
        printf("\b|\n");
    }
    printf("\n\t\t\t\tLRU\t< ");
    for (int i=0; i<64 && lru[i] != 0; i++) 
        printf("%3i,", lru[i]);
    printf("\b>\n");

    printf("\n\t\t\t\tSWAP\t[ ");
    int prox_linha = 1;
    for(lista_swap* aux = swap; aux; aux = aux->prox) {
        printf("%3i,", aux->id);
        if(prox_linha++%16 == 0)
            printf("\n\t\t\t\tSWAP\t ");
    }
    printf("\b]\n\n");
}

void configura_memoria() {
    for(int i=0; i<64; i++) {
        mem_principal[i] = 0;
        lru[i] = 0;
    }
}

unsigned swapoff(unsigned id) {
    lista_swap** aux = &swap;
    while(aux && *aux) {
        if((*aux)->id == id) {
            unsigned paginas = (*aux)->paginas;
            lista_swap* deletado = (*aux);
            if(deletado->prox)
                *aux = deletado->prox;
            else
                *aux = NULL;
            free(deletado);
            printf("\t\t\t\t(%3i)  <<     Swapoff   >>\n", id);
            mostra_memoria();
            return paginas;
        }
        aux = &((*aux)->prox);
    }
    printf("\t\t\t\t(%3i)  <<     Swapoff   >>\n", id);
    mostra_memoria();
    return 0;
}

char swapin(unsigned id, unsigned paginas) {
    if(!swap) {
        swap = (lista_swap*) calloc(1, sizeof(lista_swap));
        swap->id = id; swap->paginas = paginas;
    } 
    else {
        lista_swap* aux = swap;
        while(aux && aux->prox)
            aux = aux->prox;
        aux->prox = (lista_swap*) calloc(1, sizeof(lista_swap));
        (aux->prox)->id = id; (aux->prox)->paginas = paginas;
    }
    printf("\t\t\t\t(%3i)  <<     Swapin    >>\n", id);
    mostra_memoria();
    return 0;
}

char memoria_disponivel() {
    unsigned mem_disponivel = 0;
    for(int i=0; i<64; i++) {
        if(mem_principal[i] == 0)
            mem_disponivel++;
    }
    return mem_disponivel;
}

unsigned atualiza_lru(unsigned id) {
    int i;
    for(i=0; i<64 && lru[i]!=0; i++) {
        if(lru[i] == id) {
            for(;i<63 && lru[i+1]!=0; i++)
                lru[i] = lru[i+1];
            lru[i] = id;
            return id;
        }
    }
    if(i != 64) {
        lru[i] = id;
        return 0;
    }
}

void remove_lru(unsigned id) {
    for(int i=0; i<64 && lru[i]!=0; i++) {
        if(lru[i] == id) {
            for(;i<63 && lru[i]!=0; i++)
                lru[i] = lru[i+1];
            break;
        }
    }
}

unsigned remove_last_lru() {
    unsigned removido = lru[0];
    for(int i=0; i<63 && lru[i]!=0; i++) 
        lru[i] = lru[i+1];
    return removido;
}

char necessidade_memoria(unsigned id) {
    int nrEmMemoria = 0;
    for(int i=0; i<64 && nrEmMemoria < 4; i++) 
        if(mem_principal[i] == id)
            nrEmMemoria++;
    return (4-nrEmMemoria);
}

void adiciona_item_memoria(unsigned id) {
    int nrEmMemoria = 0; int posZero = 0;
    for(int i=0; i<64 && nrEmMemoria < 4; i++) {
        if(mem_principal[i] == id)
            nrEmMemoria++;
        if(mem_principal[i] == 0)
            posZero = i;
    }
    if(nrEmMemoria == 4)
        return;
    mem_principal[posZero] = id;
}

int swap_item_memoria(unsigned id) {
    int nrEmMemoria = 0;
    for(int i=0; i<64; i++) {
        if(mem_principal[i] == id) {
            nrEmMemoria++;
            mem_principal[i] = 0;
        }
    }
    remove_lru(id);
    swapin(id, nrEmMemoria);
    return nrEmMemoria;
}

char esta_em_swap(unsigned id) {
    lista_swap* aux = swap;
    while(aux) {
        if(aux->id == id)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void termina_processo_memoria(unsigned id) {
    remove_lru(id);
    if(esta_em_swap(id))
        swapoff(id);

    for(int i=0; i<64; i++) {
        if(mem_principal[i] == id)
            mem_principal[i] = 0;
    }
    printf("\t\t\t\t(%3i)  <<   Eliminação  >>\n", id);
    mostra_memoria();
}

void gera_pedido_memoria(unsigned id, unsigned instante) {
    if(esta_em_swap(id)) {
        unsigned nr_paginas = swapoff(id);
        atualiza_lru(id); //if != id

        while(memoria_disponivel()<nr_paginas)
            swap_item_memoria(remove_last_lru());

        for(int i=0; i<nr_paginas; i++)
            adiciona_item_memoria(id);
            
    } else {
        if(memoria_disponivel() || necessidade_memoria(id) == 0) {
            atualiza_lru(id);
            adiciona_item_memoria(id);
        } else {
            if(lru[0] != id) 
                swap_item_memoria(remove_last_lru(id));
            adiciona_item_memoria(id);
        }
    }
    printf("\t\t\t\t(%3i)  <<   Alocação   >>\n", id);
    mostra_memoria();
}

void limpa_memoria(unsigned id, unsigned instante) {
    while(swap) {
        lista_swap* elim = swap; swap = swap->prox;
        free(elim);
    }
}

void acesso_a_memoria(processo processo, unsigned tempo_global, unsigned intervalo) {
    unsigned inicioExec = processo.executado - intervalo;
    unsigned instAcesso = tempo_global - intervalo;
    unsigned offset = (inicioExec)%3;
    while((offset + intervalo) >= 3) {
        instAcesso += (3-offset);
        intervalo -= (3-offset); offset = 0;
        gera_pedido_memoria(processo.id, instAcesso);
    } 
    if(processo.executado == processo.duracao) {
        termina_processo_memoria(processo.id);
    }

}

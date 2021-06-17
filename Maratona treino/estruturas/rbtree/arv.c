#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

char novo_no(int val, arv** raiz) {
    if(!raiz) return 1;
    if (*raiz) {
        if((*raiz)->val > val) {
            if ((*raiz)->esq)
                novo_no(val, &((*raiz)->esq));
            else {
                (*raiz)->esq = (arv*) malloc (sizeof (arv));
                (*raiz)->esq->dir = NULL;
                (*raiz)->esq->esq = NULL;
                (*raiz)->esq->val = val;
                (*raiz)->esq->cor = 1;
            }
            return 0;
        } else {
            if ((*raiz)->dir)
                novo_no(val, &((*raiz)->dir));
            else {
                (*raiz)->dir = (arv*) malloc (sizeof (arv));
                (*raiz)->dir->dir = NULL;
                (*raiz)->dir->esq = NULL;
                (*raiz)->dir->val = val;
                (*raiz)->dir->cor = 1;
            }
            return 0;
        }
    } else {
        *raiz = (arv*) malloc (sizeof (arv));
        (*raiz)->val = val;
        (*raiz)->cor = 1;
        (*raiz)->dir = NULL;
        (*raiz)->esq = NULL;
        return 0;
    }
}

void imprime_arv_rec(arv* raiz, int dist) {
    if(!raiz) return;
    imprime_arv_rec(raiz->dir, dist+1);
    for(int i = 0; i < dist; i++)
        printf("  ");
    if(raiz->cor)
        printf("\e[31m\e[107m");
    else
        printf("\e[30m\e[107m");
    printf("%d\n", raiz->val);
    imprime_arv_rec(raiz->esq, dist+1);
}

void imprime_arv(arv* raiz) {
    printf("\nÁrvore:\n");
    printf("----------\e[107m\n\e[107m");
    imprime_arv_rec(raiz, 0);
    printf("\e[0m\n");
}

char procura_no(int val, arv* raiz) {
    if(!raiz) return 0;
    if(raiz->val == val) return 1;
    if(raiz->val > val) return procura_no(val, raiz->esq);
    return procura_no(val, raiz->dir);
}

void subst_mais_a_dir(arv** raiz) {
    arv** substituto = &((*raiz)->esq);
    if(!(*substituto)->dir) {
        (*substituto)->dir = (*raiz)->dir;
        arv* livre = *raiz;
        *raiz = *substituto;
        free(livre);
        return;
    }
    
    while ((*substituto)->dir)
        substituto = &((*substituto)->dir);

    arv* prox = *substituto;
    *substituto = (*substituto)->esq;
    prox->dir = (*raiz)->dir;
    prox->esq = ((*raiz)->esq)->esq;
    arv* livre = *raiz;
    *raiz = prox;
    free(livre);
}

void gera_sucessao(arv** raiz) {
    if(!raiz) return;
    if(!(*raiz)->esq && !(*raiz)->dir) {
        free(*raiz);
        *raiz = NULL;
        return;
    }
    if(!(*raiz)->esq) {
        arv* prox = (*raiz)->dir;
        free(*raiz);
        *raiz = prox;
        return;
    }    
    if(!(*raiz)->dir) {
        arv* prox = (*raiz)->esq;
        free(*raiz);
        *raiz = prox;
        return;
    }
    subst_mais_a_dir(raiz);
}

char exclui_no(int val, arv** raiz) {
    if(!raiz && !(*raiz)) return 1;
    if((*raiz)->val == val) {
        gera_sucessao(raiz);
        return 0;
    }
    if((*raiz)->val > val) return exclui_no(val, &((*raiz)->esq));
    return exclui_no(val, &((*raiz)->dir));
}

void limpa_arv(arv** raiz) {
    if(!raiz || !(*raiz)) return;
    limpa_arv(&((*raiz)->esq));
    limpa_arv(&((*raiz)->dir));
    free(*raiz);
}

arv** pega_item_por_valor(int val, arv** raiz) {
    arv** item = raiz;
    while(item && *item) {
        if((*item)->val == val)
            break;
        if((*item)->val > val)
            item = &((*item)->esq);
        else
            item = &((*item)->dir);
    }
    return item;
}

char rot_dir(int val, arv** raiz) {
    arv** item = pega_item_por_valor(val, raiz);
    if (!(*item)) return 1;
    if (!((*item)->esq)) return 1;

    arv* caido = *item;
    *item = caido->esq;
    caido->esq = (*item)->dir;
    (*item)->dir = caido;
}

char rot_esq(int val, arv** raiz) {
    arv** item = pega_item_por_valor(val, raiz);
    if (!(*item)) return 1;
    if (!((*item)->dir)) return 1;

    arv* caido = *item;
    *item = caido->dir;
    caido->dir = (*item)->esq;
    (*item)->esq = caido;
}
#include <stdio.h>
#include "arv.h"

int main () {
    printf("Este programa implementa uma árvore binária simples de inteiros\n");
    arv* raiz = NULL;
    novo_no(5, &raiz);
    novo_no(3, &raiz);
    novo_no(7, &raiz);
    novo_no(1, &raiz);
    novo_no(9, &raiz);
    novo_no(0, &raiz);
    novo_no(2, &raiz);
    novo_no(4, &raiz);
    novo_no(6, &raiz);
    novo_no(8, &raiz);
    novo_no(10, &raiz);

    imprime_arv(raiz);

    printf("O nó %d %s\n", 3, procura_no(3, raiz) ? "foi encontrado" : "não foi encontrado");
    printf("O nó %d %s\n", 2, procura_no(2, raiz) ? "foi encontrado" : "não foi encontrado");

    printf("Exclusão do item de valor 3\n");
    exclui_no(3, &raiz);

    imprime_arv(raiz);

    printf("Rotaciona à direita o item de valor 7\n");
    rot_dir(7, &raiz);

    imprime_arv(raiz);

    printf("Rotaciona à esquerda o item de valor 5\n");
    rot_esq(5, &raiz);

    imprime_arv(raiz);
    limpa_arv(&raiz);
    return 0;
}
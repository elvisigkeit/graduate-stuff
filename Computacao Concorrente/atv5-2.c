#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define tamanhoVetor 37
#define NTHREADS 2 

typedef struct {
    int *vetor, tamanho, paridade;
} t_Args;

int *geraArrayInteiros(int tamanho) {
    int *vetor = calloc(tamanho, sizeof(int));
    if (vetor == NULL) {
        printf("--ERRO: calloc(geraArrayInteiros)\n"); exit(-1);
    }
    return vetor;
}

void *maisUm (void *arg) {
    int i;
    t_Args *args = (t_Args *) arg;
    for (i=0;i<args->tamanho;i++) {
        if (args->paridade == 0) {
            if (i%2 == 0) {
                args->vetor[i]++;
            }
        }
        if (args->paridade == 1) {
            if (i%2 == 1) {
                args->vetor[i]++;
            }
        }
    }
    pthread_exit(NULL);
}

int main (void) {
    pthread_t tid_sistema[NTHREADS]; 
    int *vetor;
    t_Args arg[NTHREADS];
    int i, j;
    vetor=geraArrayInteiros(tamanhoVetor);
    for (i=0; i<tamanhoVetor; i++) {
        vetor[i]=i+1;
        printf("Valor posicao %d do vetor: %d\n", i, vetor[i]);
    }
/*    for (i=0; i<NTHREADS; i++) {
        arg[i].vetor = vetor;
        arg[i].tamanho = tamanhoVetor;
        if (i%2 == 0) {
            arg[i].paridade = 0;
        }
        if (i%2 == 1) {
            arg[i].paridade = 1;
        }
    } */
    arg[0].vetor = arg[1].vetor = vetor;
    arg[0].tamanho = arg[1].tamanho = tamanhoVetor;
    arg[0].paridade = 0; arg[1].paridade = 1;
/*    for (i=0; i<NTHREADS; i++) {
        if (pthread_create(&tid_sistema[i], NULL, maisUm, (void *) &(arg[i]))) {
            printf("--ERRO: pthread_create()\n"); exit(-4);
        }
    } */
    if (pthread_create(&tid_sistema[0], NULL, maisUm, (void *) &(arg[0]))) {
        printf("--ERRO: pthread_create()\n"); exit(-4);
    }
    if (pthread_create(&tid_sistema[1], NULL, maisUm, (void *) &(arg[1]))) {
        printf("--ERRO: pthread_create()\n"); exit(-4);
    }
    for (i=0; i<NTHREADS; i++) {
        if (pthread_join(tid_sistema[i], NULL)) {
            printf("--ERRO: pthread_join() \n"); exit(-6);
        }
    }
    for (i=0;i<tamanhoVetor;i++) {
        printf("Valor posicao %d do vetor, apos modificacao: %d\n", i, vetor[i]);
    }
    free(vetor);
    printf("--Thread principal finalizada!\n");
    pthread_exit(NULL);
}

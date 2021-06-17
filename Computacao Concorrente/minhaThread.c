#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanhoVetor 37
#define NTHREADS 2 

#ifndef _MINHA_THREAD_
#define _MINHA_THREAD_

#include <pthread.h>

typedef struct {
	unsigned nrThreads;
	pthread_t idThreads*;
} minhaThread;

minhaThread* criaThreads(unsigned nrThreads, void *(*funcao)(void *))
{
	minhaThread *threads = calloc(1, sizeof(minhaThread));
	threads->nrThreads = nrThreads;
	threads->idThreads = calloc(nrThreads, sizeof(pthread_t));
	int i;
	for (i=0; i<nrThreads; i++)
        if (pthread_create(&(threads->idThreads[i]), NULL, funcao, NULL))
            printf("--ERRO: pthread_create()\n"); exit(-4);
}

minhaThread* criaThreadsArg(unsigned nrThreads, void *(*funcao)(void *), void **arg)
{
	minhaThread *threads = calloc(1, sizeof(minhaThread));
	threads->nrThreads = nrThreads;
	threads->idThreads = calloc(nrThreads, sizeof(pthread_t));
	int i;
	for (i=0; i<nrThreads; i++)
        if (pthread_create(&(threads->idThreads[i]), NULL, funcao, arg[i]))
            printf("--ERRO: pthread_create()\n"); exit(-4);
}

void esperaThreads(minhaThread* threads)
{
	int i;
    for (i=0; i<threads->nrThreads; i++)
        if (pthread_join(threads->idThreads[i], NULL))
            printf("--ERRO: pthread_join() \n"); exit(-6);
        
}

void terminaThreads(minhaThread* threads)
{
	esperaThreads(threads);
	free(threads->idThreads);
	free(threads);
}
#endif

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

    arg[0].vetor = arg[1].vetor = vetor;
    arg[0].tamanho = arg[1].tamanho = tamanhoVetor;
    arg[0].paridade = 0; arg[1].paridade = 1;

	for (i=0;i<tamanhoVetor;i++) {
        printf("Valor posicao %d do vetor, apos modificacao: %d\n", i, vetor[i]);
    }
    free(vetor);
    printf("--Thread principal finalizada!\n");
    pthread_exit(NULL);
}

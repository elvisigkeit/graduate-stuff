#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

char sinal_recebido = 0;

void fim(int sinal) {
    sinal_recebido = 1;
}

int copia_palavra(char* palavra, char* string, unsigned indice, unsigned max_indice, unsigned max_palavra){
    int ind_palavra = 0;

    while(indice<max_indice && ind_palavra < max_palavra && string[indice] != ' ')
        palavra[ind_palavra++] = string[indice++];

    while(indice<max_indice && string[indice] == ' ')
        indice++;

    return indice;
}

int main (int argc, char* argv[]) {
    FILE *pipe, *log;
    char linha[400];
    int tempo_espera = 1;

    log = fopen("saida.log", "w");
    if(!log) {
        fprintf(stderr, "Não foi possível criar o log\n");
        return 2;
    }

    if(argc != 2) {
        fprintf(stderr, "Por favor, insira o valor da espera em segundos.\n");
        return 2;
    }

    tempo_espera = atoi(argv[1]);

    if(fork())
        return 0;

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = fim;
    sigfillset(&sa.sa_mask);
    sigdelset(&sa.sa_mask, SIGTERM);
    sigprocmask(SIG_BLOCK, &sa.sa_mask, NULL);
    sigaction(SIGTERM, &sa, NULL);

    fprintf(log, "PID\tPPID\tSTAT\tNOME\n");
    while (1) {
        fprintf(log, "###############################\n");
        pipe = popen("ps xao pid,ppid,stat,comm | awk '{if($3 == \"Z\"){print}}'", "r");
        if(!pipe) {
            fprintf(log, "Não foi possível abrir o pipe\n");
            return 3;
        }

        while(fgets(linha, sizeof(linha), pipe)) {
            int indice = 0;
            int linha_len = strlen(linha);
            char pid[15], ppid[15], stat[10], nome[100];
            indice = copia_palavra(pid , linha, indice, linha_len, 15);
            indice = copia_palavra(ppid, linha, indice, linha_len, 15);
            indice = copia_palavra(stat, linha, indice, linha_len, 10);
            indice = copia_palavra(nome, linha, indice, linha_len, 100);
            fprintf(log, "%s\t%s\t%s\t%s\n", pid, ppid, stat, nome);
        }
                
        pclose(pipe);
        fflush(log);
        if(sinal_recebido)
            break;
        sleep(tempo_espera);
    }
    fprintf(log, "\nRecebido o sinal... Terminando o processo\n");

    fclose(log);

    return 0;
}
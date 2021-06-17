#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/stat.h>

void termina_com_erro(char* erro) {
    fprintf(stderr, "%s\n", erro);
    exit(1);
}

char arquivo_regular(struct stat* status) {
    if(S_ISREG(status->st_mode))
        return 1;
    return 0;
}

char arquivo_link(struct stat* status) {        
    if(S_ISLNK(status->st_mode))
        return 1;    
    return 0;
}

void remove_link(char* arquivo) {
    printf("O arquivo é um link, sendo removido...");
    int ret = remove(arquivo);
    if(ret)
        termina_com_erro("Não foi possível apagar este link, cheque permissões.");
}

void bagunca_arquivo(char* arquivo, unsigned tamanho) {
    FILE *fp = fopen(arquivo, "w");
    unsigned largura_vetor = tamanho / sizeof(int);
    int vetor_rand[largura_vetor];

    if(!fp)
        termina_com_erro("Não foi possível escrever no arquivo, cheque permissões.");

    for(int i=0; i<largura_vetor; i++) 
        vetor_rand[i] = rand();
    
    fwrite(vetor_rand, sizeof(vetor_rand), 1, fp);

    fclose(fp);
}

void deletar_arquivo_reescrevendo(char* arquivo) {
    struct stat status;
    unsigned tamanho = 0;

    if(stat(arquivo, &status)) 
        termina_com_erro("Não foi possível abrir o arquivo");

    if(arquivo_link(&status)) {
        remove_link(arquivo);
        return;
    }

    if(!arquivo_regular(&status))
        termina_com_erro("Nesse modo, é possível apenas apagar arquivos regulares.");

    tamanho = status.st_size;    
    bagunca_arquivo(arquivo, tamanho);

    int ret = remove(arquivo);
    if(ret)
        termina_com_erro("Não foi possível apagar este arquivo, cheque permissões.");
}

void switch_opt(char opt, char* entrada) {
    printf("A deletar o arquivo: \"%s\"\n", entrada);
    switch(opt) 
    {
    case 'd':
        deletar_arquivo_reescrevendo(entrada);
        break;
    }
}

int main (int argc, char* argv[]) {
    char opt;

    if((opt = getopt(argc, argv, "r::")) == -1)  
        opt = 'd';

    if(opt == '?')
        termina_com_erro("Argumento inválido");

    if(optind == argc)
        termina_com_erro("Necessário ser indicado um arquivo");

    for(; optind < argc; optind++) 
        switch_opt(opt, argv[optind]);

    return 0;
}
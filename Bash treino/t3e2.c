#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

unsigned contador;

int walk_dir (const char *path, void (*func) (const char *))
{
    DIR    *dirp;
    struct dirent *dp;
    char    *p, *full_path;
    int    len;

    /* abre o diretório */
    if ((dirp = opendir (path)) == NULL)
    return -1;
    len = strlen (path);

    /* aloca uma área na qual, garantidamente, o caminho caberá */
    if ((full_path = malloc (len + NAME_MAX + 2)) == NULL)
    {
        closedir (dirp);
        return -1;
    }

    /* copia o prefixo e acrescenta a '/' ao final */
    memcpy (full_path, path, len);
    p = full_path + len; *p++ = '/';
    /* deixa "p" no lugar certo! */
    while ((dp = readdir (dirp)) != NULL)
    {
        /* ignora as entradas "." e ".." */
        if (strcmp (dp->d_name, ".") == 0 || strcmp (dp->d_name, "..") == 0)
            continue;
        strcpy (p, dp->d_name);

        /* "full_path" armazena o caminho */
        (*func) (full_path);
    }

    free (full_path);
    closedir (dirp);
    return 0;
}
/* end walk_dir */

void verifica_regular (const char* string) {

    struct stat status;
    
    if(stat(string, &status)) 
        perror("Erro");
        
    if(S_ISREG(status.st_mode))
        contador++;

}

void verifica_diretorio (const char* string) {

    struct stat status;
    
    if(stat(string, &status)) 
        perror("Erro");
        
    if(S_ISDIR(status.st_mode))
        contador++;
}

void verifica_link (const char* string) {

    struct stat status;
    
    if(stat(string, &status)) 
        perror("Erro");
        
    if(S_ISLNK(status.st_mode))
        contador++;
}

void verifica_bloco (const char* string) {

    struct stat status;
    
    if(stat(string, &status)) 
        perror("Erro");
        
    if(S_ISBLK(status.st_mode))
        contador++;
}

void verifica_naoestruturado (const char* string) {

    struct stat status;
    
    if(stat(string, &status)) 
        perror("Erro");
        
    if(S_ISCHR(status.st_mode))
        contador++;
}

void switch_opt(char opt, char* dir) {
    printf("Executando para o diretorio: \"%s\"\n", dir);
    contador = 0;
    switch(opt)
    {  
    case 'r':  
        if(walk_dir(dir, verifica_regular)) {
            perror("Erro");
            exit(1);
        }
        printf("%u arquivo[s] regulare[s].\n", contador);
        break;
    case 'd':  
        if(walk_dir(dir, verifica_diretorio)) {
            perror("Erro");
            exit(1);
        }
        printf("%u arquivo[s] de diretório.\n", contador);
        break;
    case 'l':
        if(walk_dir(dir, verifica_link)) {
            perror("Erro");
            exit(1);
        }
        printf("%u arquivo[s] de link.\n", contador);
        break;
    case 'b':
        if(walk_dir(dir, verifica_bloco)) {
            perror("Erro");
            exit(1);
        }
        printf("%u arquivo[s] de bloco.\n", contador);
        break;
    case 'c':  
        if(walk_dir(dir, verifica_naoestruturado)) {
            perror("Erro");
            exit(1);
        }
        printf("%u arquivo[s] não estruturado[s].\n", contador);
        break;  
    }
}

int main (int argc, char *argv[]) {
    char opt;

    if((opt = getopt(argc, argv, "r::d::l::b::c::")) == -1)  
        opt = 'r';

    if(opt == '?')
        return 1;

    if(optind == argc)
        switch_opt(opt, ".");

    for(; optind < argc; optind++) 
        switch_opt(opt, argv[optind]);
    
    return 0;
}
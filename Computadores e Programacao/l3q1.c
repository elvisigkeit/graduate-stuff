#include <errno.h> // para uso da vari ́avel errno
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TAM 128

int myopen(const char *pathname, int flags) {
	return open(pathname, flags); // retorna inteiro que  ́e o descritor do arquivo
} // seta errno=2 em caso de arquivo inexistente e retorna n ́umero negativo

ssize_t myread(int fd, void *buf) {
	return read(fd, buf, TAM);
} // retorna n ́umeros de bytes lidos se arquivo existe; 0 se arquivo vazio,-1 como erro (pg.865,866)

ssize_t mywrite(int fd, const void *buf, size_t count) {
	return write(fd, buf, count);
} // retorna n ́umero de bytes escritos (se OK), -1 como erro

int myclose(int fd) {
	return close(fd);
}

int main(int argc, char** argv) 

{
	int arq;
	char buf[TAM];
	ssize_t lidos, escritos;

	if (argc != 2) 
	{
		fprintf(stderr, "forma correta: %s <nomearquivo>\n", argv[0]);
		return 1;
	}

	printf("errno = %d\n", errno);
	
	// arq = myopen (argv[1], O_RDONLY);

	__asm__("movl $5, %%eax\n\t" // system call: open 1
			"movl %[nome], %%ebx\n\t"// nome do arquivo
			"movl %[flag], %%ecx\n\t"// flag
			"int $0x80\n\t"// chamada de sistema, retorno em %eax
			"testl %%eax, %%eax\n\t"// seta flags dependendo de arq
			"movl $2, %%ebx \n\t"// reusa reg para armazenar 2
			"cmovl %%ebx, %[erro]\n\t"// errno = 2, se arq < 0
			"movl %%eax, %[arq]"// arq = myopen (argv[1], O_RDONLY);
			:[arq]"=r"(arq), [erro]"=r"(errno)// lista de sa ́ıda
			:"r"(errno), [nome]"r"(argv[1]), [flag]""(O_RDONLY)// lista de entrada
			:"eax", "ebx", "ecx");	// registradores modificados

	printf("arq = %d\n", arq);
	printf("errno = %d\n", errno);

	if (arq < 0) {
		printf("errno = %d\n", errno);
		perror("abertura de arquivo");
		return 1;
	}

	lidos = myread(arq, buf);

	while (lidos) { // loop de leitura at ́e lidos=0
		escritos = mywrite(STDOUT_FILENO, buf, lidos);
		if (escritos != lidos)
		{
			perror("escrita:");
			return 1;
		}
		lidos = myread(arq, buf);
	};

	myclose(arq);

	return 0;

}

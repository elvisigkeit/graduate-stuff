#include <errno.h> // para uso da vari ́avel errno
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TAM 128

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
			"movl $0, %[erro]\n\t" // modo de resolver a alta impedancia do errno
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

//	lidos = myread(arq, buf);
	__asm__("movl $3, %%eax\n\t" // system call: read 3
			"movl %[arq], %%ebx\n\t"// descritor arq
			"movl %[buf], %%ecx\n\t"// buf
			"movl %[tam], %%edx\n\t"// tamanho
			"int $0x80\n\t"// chamada de sistema, retorno em %eax
			"movl %%eax, %[lidos]"// lidos = myread
			:[lidos]"=g"(lidos)// lista de sa ́ıda
			:[arq]"g"(arq), [buf]"g"(buf), [tam]"g"(TAM)// lista de entrada
			:"eax", "ebx", "ecx", "edx");	// registradores modificados
	
	while (lidos) { // loop de leitura at ́e lidos=0
//		escritos = mywrite(STDOUT_FILENO, buf, lidos);
		__asm__("movl $4, %%eax\n\t" // system call: write 4
				"movl %[stdout], %%ebx\n\t"// descritor stdout
				"movl %[buf], %%ecx\n\t"// buf
				"movl %[tam], %%edx\n\t"// largura da escrita
				"int $0x80\n\t"// chamada de sistema, retorno em %eax
				"movl %%eax, %[escritos]"// lidos = myread
				:[escritos]"=r"(escritos)// lista de sa ́ıda
				:[buf]"g"(buf), [tam]"g"(lidos), [stdout]""(STDOUT_FILENO)// lista de entrada
				:"eax", "ebx", "ecx", "edx");	// registradores modificados
		if (escritos != lidos)
		{
			perror("escrita:");
			return 1;
		}
//		lidos = myread(arq, buf);
		__asm__("movl $3, %%eax\n\t" // system call: read 3
				"movl %[arq], %%ebx\n\t"// descritor arq
				"movl %[buf], %%ecx\n\t"// buf
				"movl %[tam], %%edx\n\t"// tamanho
				"int $0x80\n\t"// chamada de sistema, retorno em %eax
				"movl %%eax, %[lidos]"// lidos = myread
				:[lidos]"=g"(lidos)// lista de sa ́ıda
				:[arq]"g"(arq), [buf]"g"(buf), [tam]"g"(TAM)// lista de entrada
				:"eax", "ebx", "ecx", "edx");	// registradores modificados
	};

//	myclose(arq);
	__asm__("movl $6, %%eax\n\t" // system call: close 6
			"movl %[arq], %%ebx\n\t"// descritor arq
			"int $0x80\n\t"// chamada de sistema, retorno em %eax
			: // lista de sa ́ıda
			:[arq]"g"(arq)// lista de entrada
			:"eax", "ebx");	// registradores modificados

	return 0;

}

/*
Arquivo das funções de fibonacci 
Autor : Elvis Nobrega
*/
#include "fibonacci-sc1.h"

void Fibonacci::computaFibonacci (int indice) {
	resultado = geraResultado (indice);
}

int Fibonacci::geraResultado (int indice) {
	if (indice == 1)
		return 1;
	else if (indice == 2)
		return 1;
	else
		return geraResultado (indice - 1) + geraResultado (indice - 2);
	
}

int Fibonacci::getResultado () {
	return resultado;
}

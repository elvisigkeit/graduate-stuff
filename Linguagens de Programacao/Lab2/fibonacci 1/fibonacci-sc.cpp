/*
Arquivo das funções de fibonacci 
Autor : Elvis Nobrega
*/
#include "fibonacci-sc.h"

int fibonacci (int indice) {
	if (indice == 1)
		return 1;
	else if (indice == 2)
		return 1;
	else
		return fibonacci (indice - 1) + fibonacci (indice - 2);
	
}


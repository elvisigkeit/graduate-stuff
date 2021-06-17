/*
Laboratório 4, exercicio 2 - arquivo principal
Autor : Elvis Nobrega
*/

#include "meunome.h"

int main () {
	MeuNome a ("joao");
	const MeuNome b ("maria");
	
	a.getNome(); b.getNome();
	
	return 0;
}
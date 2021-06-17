/*
Laboratório 4, exercicio 2 - arquivo de funções do protótipo meuNome
Autor : Elvis Nobrega
*/

#include "meunome.h"
#include <stdlib.h> 

MeuNome::MeuNome (string a) : nome ((char *) malloc ((a.length()+1) * sizeof (char))) {
	int i = 0;
	for (; i<a.length(); i++)
		nome[i] = a[i];
	nome[i] = '\0';
}

MeuNome::~MeuNome () {
	free (nome);
}

void MeuNome::getNome () {
	cout << "Nome printado nao-const : "
		<< nome << endl;
}

void MeuNome::getNome () const {
	cout << "Nome printado const : "
		<< nome << endl;
}

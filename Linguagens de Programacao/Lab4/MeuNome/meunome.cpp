/*
Laboratório 4, exercicio 1 - arquivo de funções do protótipo meunome
Autor : Elvis Nobrega
*/

#include "meunome.h"

MeuNome::MeuNome (string a) : nome (a) {}

void MeuNome::getNome () {
	cout << "Nome printado nao-const : "
		<< nome << endl;
}

void MeuNome::getNome () const {
	cout << "Nome printado const : "
		<< nome << endl;
}
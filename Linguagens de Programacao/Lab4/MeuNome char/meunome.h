/*
Laboratório 4, exercicio 2 - arquivo de protótipos
Autor : Elvis Nobrega
*/

#ifndef MNM_H
#define MNM_H

//má pratica
#include <string>
#include <iostream>
using namespace std;

class MeuNome {
	public:
		MeuNome (string );
		~MeuNome ();
		void getNome ();
		void getNome () const;
	private:
		char *nome;
};

#endif
/*
Laboratório 4, exercicio 1 - arquivo de protótipos
Autor : Elvis Nobrega
*/

#ifndef MNM_H
#define MNM_H

#include <string>
#include <iostream>
using namespace std;

class MeuNome {
	public:
		MeuNome (string );
		void getNome ();
		void getNome () const;
	private:
		string nome;
};

#endif
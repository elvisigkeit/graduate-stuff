/*Arquivo de protótipos da classe tabela
Autor: Elvis Nobrega                   */

#include <vector>
#include "email.h"

#ifndef TABELA_H
#define TABELA_H

using namespace std;

class Tabela {
	public:
		Tabela ();
		void mostraTabela () const;
		void adicionaEmail (string , string , string , string , string , bool);
		string deletaEmail (int );
		void totalEmails () const;
		void classificaEmails ();
		unsigned int nrEmails () const;
		void totalSpams () const;
		string mostraEmail (int );
	private:
		vector <Email> vectorEmails; //ID Será o índice no vector
		int spams;
};

#endif

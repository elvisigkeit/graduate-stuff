/*
Arquivo de protótipos do programa principal da agenda
Autor : Elvis Nobrega
*/
#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Cadastro {
	public:
		void setNome(string );
		void setProfissao(string );
		void setIdade(int );
		string getNome();
		string getProfissao();
		int getIdade();
	private:
		string nome , profissao ;
		int idade ;
};

class Agenda {
	public:
		void insertCadastro(Cadastro &);
		void getCadastros();
	private:
		static int nrCadastros;
		static const int maxCadastros = 3;
		vector <Cadastro> cadastros;
};

#endif

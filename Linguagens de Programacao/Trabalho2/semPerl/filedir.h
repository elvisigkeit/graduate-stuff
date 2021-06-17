/* Arquivo filedir.h para manipulação dos e-mails 
Autor: Elvis Nobrega                           */

#include <dirent.h>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "tabela.h"

/*Classe filedir, responsável pela manipulação dos diretórios e arquivos nos mesmos
Ela se comunica com a classe tabela, que organiza os emails como uma interface
Possui métodos de relação com tabela e métodos de inicialização e configuração da tabela*/

#ifndef FILEDIR_H
#define FILEDIR_H

using namespace std;

class FileDir {
	public:
		FileDir (string );
		~FileDir ();
		void openDir ();
		int readDir ();
		int getDirSize ();
		void setNameDir (string );
		void listDir ();
		void deletar (unsigned int );
		void mostraEmail (unsigned int );
		void atualizaTabela ();
		void mostraTabela () const;
		void totalEmails () const;
		void totalSpams () const;
		unsigned int nrEmails () const;
	private:
		Tabela tabela;
		vector <string> dir;
		string nameDir;
		DIR *dp;
		struct dirent *dirp;
};

#endif

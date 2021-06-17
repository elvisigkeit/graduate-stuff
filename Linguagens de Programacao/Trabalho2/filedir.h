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

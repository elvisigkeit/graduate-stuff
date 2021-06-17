/* Arquivo filedir.cpp para manipulação dos e-mails 
Autor: Elvis Nobrega                             */

#include "filedir.h"

FileDir::FileDir (string n) {
	setNameDir (n);
	openDir ();
}

FileDir::~FileDir () {
	if (dp != NULL) closedir (dp);
}

void FileDir::openDir () {
	if((dp = opendir(nameDir.c_str())) == NULL) {
		cout << "Error opening " << nameDir << endl;
		exit (1);
	}
}

void FileDir::deletar (unsigned int codigo) {
	if (codigo<0 || codigo>=nrEmails()) {
		cout << "ID inexistente, por favor, verificar" << endl;
	}else {
		//pega o array de char's da string que define o nome do email a ser deletado
		const char * deletando = (tabela.deletaEmail(codigo)).c_str();
		remove(deletando);
		cout << "Email " << codigo << " removido" << endl;
	}
}

int FileDir::readDir () {
	dir.clear ();
	while ((dirp = readdir(dp)) != NULL) {
		dir.push_back(string(dirp->d_name));
	}
	rewinddir (dp);
	return dir.size ();
}

void FileDir::listDir () {
	for (unsigned i = 0; i < dir.size (); i++) {
		cout << dir.at (i) << endl;
	}
}

void FileDir::setNameDir (string n) {
	nameDir = n; 
}

void FileDir::mostraEmail (unsigned int ID) {
	if (ID<0 || ID>=nrEmails()){
		cout << "ID inexistente, por favor, verificar" << endl;
	}else {
		string linha;
		//pega o array de char's do nome do email (arquivo) a ser lido
		const char * nome = (tabela.mostraEmail(ID)).c_str();
		ifstream email (nome, ios::in);
		if (!email) {
			cout << "Email nao pode ser lido" << endl;
			exit (1);
		}
		while (!email.eof()) {
			getline(email, linha);
			cout << linha << endl;
		}
		email.close();
	}
}

void FileDir::mostraTabela() const {
	tabela.mostraTabela();
}

void FileDir::totalEmails () const {
	tabela.totalEmails();
}

void FileDir::totalSpams () const {
	tabela.totalSpams();
}

int FileDir::getDirSize () { 
	return dir.size (); 
}

unsigned int FileDir::nrEmails () const {
	return tabela.nrEmails();
}

//método mais importante, onde é montada a tabela de emails
void FileDir::atualizaTabela () {
	//int nrArquivos = readDir();
}

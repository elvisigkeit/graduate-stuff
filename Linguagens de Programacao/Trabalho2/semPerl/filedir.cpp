/* Arquivo filedir.cpp para manipulação dos e-mails 
Autor: Elvis Nobrega                             */

#include "filedir.h"

FileDir::FileDir (string n) {
	setNameDir (n);
	openDir ();
}
//Construtor que cria um filedir baseada em uma string de diretório

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
//função deletar, que deleta um email da tabela e da pasta, escolhido pela ID de entrada

int FileDir::readDir () {
	dir.clear ();
	while ((dirp = readdir(dp)) != NULL) {
		dir.push_back(string(dirp->d_name));
	}
	rewinddir (dp);
	return dir.size ();
}
//função responsável por pegar todos os nomes dos arquivos do diretório

void FileDir::listDir () {
	for (unsigned i = 0; i < dir.size (); i++) {
		cout << dir.at (i) << endl;
	}
}
//função inutilizada responsável por mostrar todos os arquivos que o diretório contém

void FileDir::setNameDir (string n) {
	nameDir = n; 
}
//função que define o nome do diretório

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
//função que pega os dados do email na tabela, e então mostra esses e o conteúdo do arquivo

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

void FileDir::atualizaTabela () {
	/*int nrArquivos = readDir();
	for (unsigned int i = 0; i<dir.size(); i++) {
		//trabalha com cada email, pelo nome dir[i], usando perl
		tabela.adicionaEmail(dados pegos)
	}
	*/
}
//por fim o método onde é criada e atualizada a tabela
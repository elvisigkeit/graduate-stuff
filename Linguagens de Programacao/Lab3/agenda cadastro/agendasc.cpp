/*
Arquivo das funções da classe agenda 
Autor : Elvis Nobrega
*/
#include "agendasc.h"

void Cadastro::setNome (string nme) {
	nome = nme;
}

void Cadastro::setProfissao (string prof) {
	profissao = prof;
}

void Cadastro::setIdade (int idd) {
	idade = idd;
}

string Cadastro::getNome () {
	return nome;
}

string Cadastro::getProfissao () {
	return profissao;
}

int Cadastro::getIdade () {
	return idade;
}

int Agenda::nrCadastros = 0;

void Agenda::insertCadastro (Cadastro &cadastro) {
	if (nrCadastros<maxCadastros) {
		cadastros[nrCadastros] = cadastro;
		nrCadastros++;
	}
}

void Agenda::getCadastros() {
	for (int i=0; i<nrCadastros; i++) {
		string nom = ((cadastros[i]).getNome()), prof = ((cadastros[i]).getProfissao());
		int idad = ((cadastros[i]).getIdade());
		cout << "Nome " << i+1 << ": "
			<< nom << endl;
		cout << "Profissao " << i+1 << ": "
			<< prof << endl;
		cout << "Idade " << i+1 << ": "
			<< idad << endl;
	}
}

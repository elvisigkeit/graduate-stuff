/*
Arquivo das funções da classe agenda 
Autor : Elvis Nobrega
*/
#include "agendasc.h"

Agenda::Agenda (int maximo) {
	maxNomes = maximo;
}

void Agenda::setNames() {
	if (getNrNomes() <= maxNomes){ //verifica se esta no maximo
		string nome;
		cout << "Por favor, insira o nome: ";
		getline (cin, nome);
		if (nome.length()>10){ //verifica se esta dentro dos parametros
			cout << "\nNome muito grande, string limitada a 10 caracteres." << endl;
			nome = nome.substr(0, 10);
		}
		Names.push_back (nome);
	}
}

int Agenda::getNrNomes() {
	return Names.size();
}

void Agenda::getNames() {
	for (int i=0; i<getNrNomes(); i++) {
		cout << "Nome " << i+1 << ": "
			<< Names[i] << endl;
	}
}

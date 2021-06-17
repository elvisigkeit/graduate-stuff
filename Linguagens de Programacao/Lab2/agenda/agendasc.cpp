/*
Arquivo das funções da classe agenda 
Autor : Elvis Nobrega
*/
#include "agendasc.h"

void Agenda::setNames() {
	string nome;
	for (int i=0; i<3; i++) {
		cout << "Por favor, insira o nome: ";
		cin >> nome;
		if (nome.length()>10){
			cout << "\nNome muito grande, string limitada a 10 caracteres." << endl;
			nome = nome.substr(0, 9);
		}
		Names[i] = nome;
	}
}

void Agenda::getNames() {
	for (int i=0; i<3; i++) {
		cout << "Nome " << i+1 << ": "
			<< Names[i] << endl;
	}
}

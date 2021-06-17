/*Arquivo de implementação da classe tabela
Autor: Elvis Nobrega                      */

#include "tabela.h"
#include <iomanip>
#include <iostream>

Tabela::Tabela () { spams = 0; }

void Tabela::mostraTabela () const {
	cout << "\033[2J\033[1;1H";
	cout << "|" << "   ID   " << "|" << "     Origem     " << "|" << "    Titulo    " 
	<< "|" << "      Data      " << "|" << "   Hora   " << "|" << " SPAM? " << "|" << endl;
	for (unsigned int i = 0; i<vectorEmails.size(); i++)
		cout << "| " << setw(6)  << i
			<< " | " << setw(16) << vectorEmails[i].getOrigem()
			<< " | " << setw(14) << vectorEmails[i].getTitulo() 
			<< " | " << setw(16) << vectorEmails[i].getData() 
			<< " | " << setw(10) << vectorEmails[i].getHora() 
			<< " | " << setw(7)  << vectorEmails[i].getSPAM() << "|" << endl;
}

void Tabela::adicionaEmail (string name, string orig, string title, string date, string hour, bool spm) {
	Email novo (name, orig, title, date, hour, spm);
	vectorEmails.push_back(novo);
}

string Tabela::deletaEmail (int ID) { 
	string nome = vectorEmails[ID].getNome();
	vectorEmails.erase (vectorEmails.begin()+ID);
	return nome;
}

void Tabela::totalEmails () const {
	cout << "A tabela tem um total de " << vectorEmails.size() << " e-mails" << endl;
}

unsigned int Tabela::nrEmails() const {
	return vectorEmails.size();
}

void Tabela::classificaEmails () {
	for (unsigned int i = 0; i<vectorEmails.size(); i++);
		//if (ehSPAM()) spams++;
}
void Tabela::totalSpams () const {
	cout << "A tabela tem um total de " << spams << " SPAMs" << endl;
}
string Tabela::mostraEmail (int ID) {
	cout << "Informações do email : " << vectorEmails[ID].getNome() << endl;
	cout << "| " << setw(6)  << ID
		<< " | " << setw(16) << vectorEmails[ID].getOrigem()
		<< " | " << setw(14) << vectorEmails[ID].getTitulo() 
		<< " | " << setw(16) << vectorEmails[ID].getData() 
		<< " | " << setw(10) << vectorEmails[ID].getHora() 
		<< " | " << setw(7)  << vectorEmails[ID].getSPAM() << "|" << endl;
	return vectorEmails[ID].getNome();
}

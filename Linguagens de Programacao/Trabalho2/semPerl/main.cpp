/* Programa Principal para manipulação de e-mails
Autor: Elvis Nobrega                           */

#include <iostream>
#include "filedir.h"
#include "email.h"

using namespace std;

int main () {
	FileDir f (".");
	string option, file;
	unsigned int code;
	
	cout << "Bem vindo ao programa de manipulação de emails!" << endl;
	while (1) {
		cout << "Entre com a operação desejada:\n"
			<< "Ou digite a opcao \"ajuda\" para ver o menu" << endl;
		getline (cin, option);
		if (!option.compare("exibir-todos")) {
			cout << "Os emails da pasta sao:"<< endl;
			for (unsigned int i = 0; i<f.nrEmails(); i++)
				f.mostraEmail(i);
			
		} else if (!option.compare("remove")) {
			cout << "Digite o código do email a ser deletado:" << endl;
			cin >> code;
			f.deletar(code);
			
		} else if (!option.compare("sair")) {
			cout << "Saindo..." << endl;
			break;
			
		} else if (!option.compare("ajuda")) {
			cout << "\033[2J\033[1;1H";
			cout << "Menu de ajuda ao usuario" << endl;
			cout << "\n-Para remover um email, use a operacao \"remove\"" << endl;
			cout << "-Para exibir todos os emails, use a operacao \"exibir-todos\"" << endl;
			cout << "-Para classificar os emails, use a operacao \"classifica\"" << endl;
			cout << "-Para exibir o numero total de emails, use a operacao \"total-emails\"" << endl;
			cout << "-Para exibir o numero total de spams, use a operacao \"total-spams\"" << endl;
			cout << "-Para exibir um email especifico, use a operacao \"mostra-email\"\n" << endl;
			
		} else if (!option.compare("tabela")) {
			f.mostraTabela();
		
		} else if (!option.compare("classifica")) {
			//classifica os emails
		
		} else if (!option.compare("total-emails")) {
			f.totalEmails();
			
		} else if (!option.compare("total-spams")) {
			f.totalSpams();
			
		} else if (!option.compare("mostra-email")) {
			cout << "Digite a ID do email a ser mostrado:" << endl;
			cin >> code;
			cout << "\033[2J\033[1;1H";
			f.mostraEmail(code);
			
		} else {
			cout << "Operação não encontrada.\n"
			<< "Digite a opção \"ajuda\" para ver o menu" << endl;
			
		}
	}
	//menu responsavel pelas mensagens
	
	return 0;
}

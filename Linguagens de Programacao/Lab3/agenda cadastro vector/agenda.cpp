/*
Arquivo do programa principal da agenda
Autor : Elvis Nobrega
*/
#include "agendasc.h"

int main () {
	Cadastro a, b;
	a.setNome("abc"); a.setProfissao("Jjj"); a.setIdade(22);
	b.setNome("def"); b.setProfissao("addd"); b.setIdade(23);
	
	Agenda agenda;
	agenda.insertCadastro (a); agenda.insertCadastro(b);
	agenda.getCadastros();
	
	return 0;
}

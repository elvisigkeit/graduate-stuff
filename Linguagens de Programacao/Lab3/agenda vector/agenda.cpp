/*
Arquivo do programa principal da agenda
Autor : Elvis Nobrega
*/
#include "agendasc.h"

int main () {
	Agenda agn(2);
	agn.setNames();
	agn.setNames();
	cout << "\nOs nomes inclusos na agenda são:" << endl;
	agn.getNames();
}

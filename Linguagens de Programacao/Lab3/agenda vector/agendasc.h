/*
Arquivo de protótipos do programa principal da agenda
Autor : Elvis Nobrega
*/
#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Agenda {
	public:
		Agenda (int );
		void setNames();
		void getNames();
		int getNrNomes();
	private:
		int maxNomes;
		vector <string> Names;
};

#endif

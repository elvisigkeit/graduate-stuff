/*
Arquivo de protótipos do programa principal da agenda
Autor : Elvis Nobrega
*/
#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include <iostream>

using namespace std;

class Agenda {
	public:
		void setNames();
		void getNames();
		int getNrNomes();
	private:
		static int nrNomes = 0;
		static const int maxNomes = 3;
		string Names[maxNomes];
};

#endif

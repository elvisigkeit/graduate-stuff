/*Arquivo de protótipos do exercício de relógios
Autor - Elvis Nobrega					      */

#ifndef RLG_H
#define RLG_H

#include <iostream>
#include <time.h>

using namespace std;

class Relogio {
	public:
		Relogio ();
		void resetHora ();
	private:
		time_t hora;
		struct tm *infoHora;
		int segundos, minutos, horas;
};

#endif
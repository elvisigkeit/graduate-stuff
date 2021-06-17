/*
Arquivo de protótipos do programa principal
Autor : Elvis Nobrega
*/
#ifndef PARAL_H
#define PARAL_H

#include <iostream>

using namespace std;

class Paralelepipedo {
	public:
		Paralelepipedo (float, float, float);
		void setVolume (float, float, float);
		float getVolume () const;
	private:
		float largura, altura, comprimento;
		float volume;
};

#endif

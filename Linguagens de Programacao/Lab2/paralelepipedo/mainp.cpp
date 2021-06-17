/*
Arquivo do programa principal do programa de paralelepipedos
Autor : Elvis Nobrega
*/
#include "paralelepipedo.h"

int main () {
	Paralelepipedo cubo (1, 1, 1);
	cout << "Paralelepipedo de 1x1x1, volume = " << cubo.getVolume() << endl;
	cubo.setVolume(2, 2, 2);
	cout << "Paralelepipedo de 2x2x2, volume = " << cubo.getVolume() << endl;
	
	return 0;
}
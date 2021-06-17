/*
Arquivo do programa principal do programa de distancias
Autor : Elvis Nobrega
*/
#include "distancia.h"

int main () {
	Distancia dist;
	
	dist.setPontos (1, 1, 1, 2, 1, 2);
	dist.getPontos ();
	cout << "Para esses pontos," << endl;
	dist.getDistancia();
	
	return 0;
}

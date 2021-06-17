/*
Arquivo de protótipos do programa principal
Autor : Elvis Nobrega
*/
#ifndef DIST_H
#define DIST_H

#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
	public:
		void setX(double);
		void setY(double);
		void setZ(double);
		double getX();
		double getY();
		double getZ();
	private:
		double x, y, z; 
};

class Distancia {
	public:
		Distancia ();
		void setPontos (double, double, double, double, double, double);
		void getPontos ();
		void getDistancia ();
	private:
		void setDistancia ();
		Ponto a, b;
		double distancia;
};

#endif

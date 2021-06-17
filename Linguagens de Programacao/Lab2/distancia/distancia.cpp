/*
Arquivo das funções de distancia 
Autor : Elvis Nobrega
*/
#include "distancia.h"

Distancia::Distancia (){
	distancia = 0;
}

void Distancia::setPontos (double ax, double ay, double az, double bx, double by, double bz){
	a.setX(ax); a.setY(ay); a.setZ(az);
	b.setX(bx); b.setY(by); b.setZ(bz);
}

void Distancia::getPontos (){
	cout << "Os pontos são:\n"
		 << "A = (" << a.getX() << "," << a.getY() << "," << a.getZ() << ")" << endl;
	cout << "B = (" << b.getX() << "," << b.getY() << "," << b.getZ() << ")" << endl;
}

void Distancia::getDistancia (){
	setDistancia();
	cout << "A distancia eh: "<< distancia << endl;
}

void Distancia::setDistancia (){
	distancia = sqrt (((a.getX()-b.getX())*(a.getX()-b.getX())) + ((a.getY()-b.getY())*(a.getY()-b.getY())) + ((a.getZ()-b.getZ())*(a.getZ()-b.getZ())));
}

void Ponto::setX(double X){
	x = X;
}

void Ponto::setY(double Y){
	y = Y;
}
void Ponto::setZ(double Z){
	z = Z;
}

double Ponto::getX(){
	return x;
}

double Ponto::getY(){
	return y;
}

double Ponto::getZ(){
	return z;
}

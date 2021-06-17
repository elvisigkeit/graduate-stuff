/*
Arquivo do programa principal da função de fibonacci
Autor : Elvis Nobrega
*/
#include <iostream>
#include "fibonacci-sc1.h"

using namespace std;

int main () {
	Fibonacci a;
	int indice;
	
	cout << "Por favor, indique o indice : ";
	cin >> indice;
	
	a.computaFibonacci(indice);
	
	cout << "O resultado e: "
		<< a.getResultado() << endl;
	return 0;
}
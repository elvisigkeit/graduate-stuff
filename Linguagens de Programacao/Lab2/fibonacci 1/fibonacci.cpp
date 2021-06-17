/*
Arquivo do programa principal da função de fibonacci
Autor : Elvis Nobrega
*/
#include <iostream>
#include "fibonacci-sc.h"

using namespace std;

int main () {
	int indice;
	
	cout << "Por favor, indique o indice : ";
	cin >> indice;
	
	cout << "O resultado e : "
		<< fibonacci (indice);
	return 0;
}
#include <iostream>
#include <iomanip>

using namespace std;

int main () 
{
	//cria as variaveis
	double nota1, nota2, nota3, media;
	//pega as variaveis
	cin >> nota1 >> nota2 >> nota3;
	//efetua as variaveis
	media = (2*nota1 + 3*nota2 + 5*nota3)/10;
	//mostra as variaveis 
	cout << "MEDIA = " << fixed << setprecision(1) << media << endl;
	return 0;
}

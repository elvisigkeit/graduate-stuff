//inicio
#include <iostream>
#include <iomanip>

using namespace std;

int main () 
{
//cria as variaveis
	double nota1, nota2, media;
//pega as variaveis
	cin >> nota1 >> nota2;
//pesoNota + pesoNota
	media = 3.5*nota1 + 7.5*nota2;
	media = media/11;
//mostra as variaveis
	cout << "MEDIA = " << fixed << setprecision(5) << media << endl;
//fim
return 0;
}

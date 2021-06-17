#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () 
{
//cria as variaveis
	string nome;
	double salarioFixo, vendas, salarioTotal;
//pega as variaveis
	cin >> nome >> salarioFixo >> vendas;
//calcula as variaveis
	salarioTotal = salarioFixo + vendas*0.15;	
//mostra o resultado
	cout << "TOTAL = R$ " << fixed << setprecision(2) << salarioTotal << endl;
	return 0;
}

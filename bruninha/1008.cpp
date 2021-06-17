#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
//cria as variaveis
	int funcionario, horasTrabalhadas;
	float recebePorHora, salario;
//pede as variaveis
	cin >> funcionario >> horasTrabalhadas >> recebePorHora;
//numero de horas multiplicado pelo valor que recebe p/ hora
	salario = horasTrabalhadas*recebePorHora;
//mostra as variaveis
	cout << "NUMBER = " << funcionario << endl;
	cout << "SALARY = U$ " << fixed << setprecision(2) << salario << endl;
	return 0;
}

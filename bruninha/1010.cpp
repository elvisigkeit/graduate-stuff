#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
//cria as variaveis
	int codigo1, codigo2, numeroDePecas1, numeroDePecas2;
	float valorUnitario1, valorUnitario2, valorFinal;
//pega as variaveis
	cin >> codigo1 >> numeroDePecas1 >> valorUnitario1;
	cin >> codigo2 >> numeroDePecas2 >> valorUnitario2; 
//multiplica o numeroDePecas pelo valorUnitario depois soma os resultados
	valorFinal = (numeroDePecas1*valorUnitario1) + (numeroDePecas2*valorUnitario2);
//mostra o valorAPagar
	cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << valorFinal << endl;
	return 0;
}

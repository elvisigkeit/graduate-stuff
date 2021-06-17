#include <iostream>

using namespace std;

int main() {
//cria as variaveis
	int valorLido, notasDe100=0, notasDe50=0, notasDe20=0, notasDe10=0, notasDe5=0, notasDe2=0, notasDe1=0; 
//pega as variaveis
	cin >> valorLido;
//decompoe o valor
	if (valorLido>100){
		notasDe100 = valorLido/100;
	}
	if (valorLido>50){
		notasDe50 = (valorLido-(notasDe100*100))/50;
	}
	if (valorLido>20){
		notasDe20 = (valorLido-((notasDe100*100)+(notasDe50*50)))/20;
	}
	if (valorLido>10){
		notasDe10 = (valorLido-((notasDe100*100)+(notasDe50*50)+(notasDe20*20)))/10;
	}
	if (valorLido>5){
		notasDe5 = (valorLido-((notasDe100*100)+(notasDe50*50)+(notasDe20*20)+(notasDe10*10)))/5;
	}
	if (valorLido>2){
		notasDe2 = (valorLido-((notasDe100*100)+(notasDe50*50)+(notasDe20*20)+(notasDe10*10)+(notasDe5*5)))/2;
	}
	if (valorLido>1){
		notasDe1 = (valorLido-((notasDe100*100)+(notasDe50*50)+(notasDe20*20)+(notasDe10*10)+(notasDe5*5)+(notasDe2*2)))/1;
	}
//mostra o valor
	cout << valorLido  << endl;
	cout << notasDe100 << " nota(s) de R$ 100,00" << endl;
	cout << notasDe50  << " nota(s) de R$ 50,00"  << endl;
	cout << notasDe20  << " nota(s) de R$ 20,00"  << endl;
	cout << notasDe10  << " nota(s) de R$ 10,00"  << endl;
	cout << notasDe5   << " nota(s) de R$ 5,00"   << endl;
	cout << notasDe2   << " nota(s) de R$ 2,00"   << endl;
	cout << notasDe1   << " nota(s) de R$ 1,00"   << endl;

	return 0;
}

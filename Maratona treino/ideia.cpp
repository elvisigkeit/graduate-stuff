#include <iostream>
#include <utility>

using namespace std;

int main () {
	int P, N, i, estado=BAIXO;
	//Pegando as entradas
	cin >> P;
	cin >> N;

	pair <int, int> pretas[N];
	pair <int, int> brancas[N];

	for (i=0; i<N; i++){
		cin >> pretas[i].first >> pretas[i].second;
			
	}
	for (i=0; i<N; i++){
		cin >> brancas[i].first >> brancas[i].second;
	}

	vector < pair < pair <int, int>, pair <int, int> > > atual;
	atual.emplace_back(make_pair(), make_pair());
	atual.second.first = N; atual.second.second = N;
	
	int maior = 0;
	for (i=0; i<N; i++){
		int maiorQC=0, maiorQB=0, maiorQD=0, maiorQE=0;
		maiorQC = pretas[i].second-atual.first.second; 
		maiorQB = atual.second.second-pretas[i].second;
		maiorQD = atual.second.first-pretas[i].first;  
		maiorQE = pretas[i].first-atual.first.first;
		if(maior<maiorQC){
			maior = maiorQC;
			;
		}
		if(maior<maiorQB){
			maior = maiorQB;
			;
		}
		if(maior<maiorQD){
			maior = maiorQD;
			;
		}
		if(maior<maiorQE){
			maior = maiorQD;
			;
		}
	}

	return 0;
}

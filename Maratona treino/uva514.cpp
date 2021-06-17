#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	vector <bool> resultados;
	vector <int> espacos;
	unsigned i, j;
	bool fim;
	
	do {
		unsigned tamanho;
		fim = false;

		cin >> tamanho;

		if (tamanho==0)
			break;
		
		do{

			int listaSai[tamanho];
			vector <int> pilhaTrens;

			for (i=0; i<tamanho; i++){
				cin >> listaSai[i];
				if (i == 0 && listaSai[0]==0){
					fim = true;
					break;
				}
			}
			
			if (!fim){
				for(i=0, j=0; i<tamanho; i++){
					bool igual = false;
					pilhaTrens.push_back(i+1);
					do{
						int atual = pilhaTrens[pilhaTrens.size()-1];
						pilhaTrens.pop_back();
						if(atual==listaSai[j]){
							j++;
							igual = true;
						}else{
							igual = false;
							pilhaTrens.push_back(atual);
						}
					}while(igual && !pilhaTrens.empty());
				}
	
				if (pilhaTrens.empty())
					resultados.push_back(true);
				else
					resultados.push_back(false);
			}

		}while(fim==false);

		espacos.push_back(resultados.size());

	
	}while(1);

	i = 0;
  j = 0;
	while(i<resultados.size()){
		bool resultado = resultados[i];
		i++;
		if(i-1==espacos[j] && i!=1){
			j++;
			cout << "\n";
		}
		if (resultado)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	cout << "\n";


	return 0;
}

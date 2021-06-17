#include <iostream>
#include <vector>

using namespace std;

bool portalNaoPassou(pair<int, int>* pri, pair<int, int>* seg){
	if(pri)
		if(seg)
			return 1;
	return 0;
}

int main () 
{
	int n, m;

	cin >> n >> m;

	char matriz[n][m];
	int dist[n][m];
	int* pai[n][m];
	vector< pair<int, int>* > filaEntrada;
	pair<int, int>* segPortal = NULL;
	pair<int, int>* priPortal = NULL;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			cin >> matriz[i][j];
			if (matriz[i][j] == '2'){
				if (!priPortal)
					priPortal = new pair<int, int> (i, j);
				else
					segPortal = new pair<int, int> (i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			pai[i][j] = NULL;

	pair<int, int>* primeiro = new pair<int, int> (0,0);
	filaEntrada.push_back(primeiro);
	pai[0][0] = &(dist[0][0]);
	dist[0][0] = -1;
	dist[n-1][m-1] = -1;

	for (unsigned atual = 0; atual<filaEntrada.size(); atual++)
	{
		int i = filaEntrada[atual]->first;
		int j = filaEntrada[atual]->second;
		dist[i][j] = (*(pai[i][j]))+1;
		if(matriz[i][j] == '2'){
			if (portalNaoPassou(priPortal, segPortal)) {
				if(priPortal->first==i && priPortal->second==j){
					pai[segPortal->first][segPortal->second] = &(dist[i][j]);
					filaEntrada.push_back(segPortal);
					delete priPortal;
					priPortal = NULL;
				}else{
					pai[priPortal->first][priPortal->second] = &(dist[i][j]);
					filaEntrada.push_back(priPortal);
					delete segPortal;
					segPortal = NULL;
				}		
			}else{
				dist[i][j] -= 1;
			}
		}

		if (i==n-1 && j==m-1)
			break;


		if (i > 0){
			pair<int, int>* esquerda = new pair<int, int> (i-1, j);
			if (matriz[i-1][j] == '2' && !pai[i-1][j]){
				pai[i-1][j] = &(dist[i][j]);
				filaEntrada.push_back(esquerda);
			}else{
				if (matriz[i-1][j] == '0' && !pai[i-1][j]){
					pai[i-1][j] = &(dist[i][j]);
					filaEntrada.push_back(esquerda);
				}else{
					delete esquerda;
				}
			}
		}				
		if (j > 0){
			pair<int, int>* cima = new pair<int, int> (i, j-1);
			if (matriz[i][j-1] == '2' && !pai[i][j-1]){
				pai[i][j-1] = &(dist[i][j]);
				filaEntrada.push_back(cima);
			}else{
				if (matriz[i][j-1] == '0' && !pai[i][j-1]){
					pai[i][j-1] = &(dist[i][j]);
					filaEntrada.push_back(cima);
				}else{
					delete cima;
				}
			}
		}
		if (i < (n-1)){
			pair<int, int>* direita = new pair<int, int> (i+1, j);
			if (matriz[i+1][j] == '2' && !pai[i+1][j]){
				pai[i+1][j] = &(dist[i][j]);
				filaEntrada.push_back(direita);
			}else{
				if (matriz[i+1][j] == '0' && !pai[i+1][j]){
					pai[i+1][j] = &(dist[i][j]);
					filaEntrada.push_back(direita);
				}else{
					delete direita;
				}
			}
		}				
		if (j < (m-1)){
			pair<int, int>* baixo = new pair<int, int> (i, j+1);
			if (matriz[i][j+1] == '2' && !pai[i][j+1]){
				pai[i][j+1] = &(dist[i][j]);
				filaEntrada.push_back(baixo);
			}else{
				if (matriz[i][j+1] == '0' && !pai[i][j+1]){
					pai[i][j+1] = &(dist[i][j]);
					filaEntrada.push_back(baixo);
				}else{
					delete baixo;
				}
			}
		}

	}	

	for (auto atual : filaEntrada)
		delete atual;
	delete segPortal;

	cout << dist[n-1][m-1] << endl;

	return 0;
}

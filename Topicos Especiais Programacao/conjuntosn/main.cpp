#include <iostream>
#include <vector>

using namespace std;

void encontraConjuntos (int valor, int prof, int n, int k, vector<int>& caminho, vector<vector<int> >& conjuntos) {
    if(k == 0) {
        conjuntos.push_back(vector<int>());
        return;
    }

    if(prof == 0) {
        for (int i=0; i<n; i++)
            encontraConjuntos(i, 1, n, k, caminho, conjuntos);
        return;
    }

    if(prof == k) {
        caminho.push_back(valor);
        conjuntos.push_back(caminho);
        caminho.pop_back();
        return;
    }

    for(int i=1+valor; i<n; i++) {
        caminho.push_back(valor);
        encontraConjuntos(i, prof+1, n, k, caminho, conjuntos);
        caminho.pop_back();
    }
}

void printaConjuntos(vector<vector<int> > conjuntos) {
    for(auto conjunto : conjuntos) {
        bool primeiro = true;
        cout << "{ ";
        for(auto atual : conjunto) {
            if(primeiro) {
                primeiro = false;
                cout << atual;
            } else {
                cout << ", " << atual;
            }
        }
        cout << " }" << endl;
    }
}

int main () {
    int n;
    int k;
    vector<vector<int> > conjuntos;
    vector<int> caminho;
    cout << "Insira n e k, sequencialmente:" << endl;
    cin >> n;
    cin >> k;

    encontraConjuntos(0, 0, n, k, caminho, conjuntos);

    printaConjuntos(conjuntos);

    return 0;
}
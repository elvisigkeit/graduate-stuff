#include <iostream>
#include <list>
#include <unordered_set>
#include <string>

using namespace std;

list<char> solucaoFinal;
unordered_set<string> inclusos;

bool verifica_acao_ja_feita (int esq, int dir) {
    string atual = esq + "," + dir;
    
    auto indice = inclusos.find(atual);

    if(indice == inclusos.end()) {
        inclusos.insert(atual);
        return false;
    }
    
    return true;
}

void percorre (list<int> fila, list<char>& solucao, int esq, int dir) {

    cout << "Fila: ";
    for (int atual : fila)
        cout << atual << " ";
    cout << endl << "Solucao: ";
    for (char atual : solucao)
        cout << atual << " ";
    cout << endl << endl; 

    if(esq < dir) {
        if(verifica_acao_ja_feita(esq, dir))
            return;
    }
    else {
        if(verifica_acao_ja_feita(esq, dir))
            return;
    }
    
    if (solucao.size() > solucaoFinal.size())
        solucaoFinal = solucao;

    if(fila.empty())
       return;

    int atual = fila.front();
    fila.pop_front();
    if(atual < esq) {
        solucao.push_back('E');
        percorre(fila, solucao, esq-atual, dir);
        solucao.pop_back();
    }
    if(atual < dir) {
        solucao.push_back('D');
        percorre(fila, solucao, esq, dir-atual);
        solucao.pop_back();
    }
}

int main() {
    int L;
    int i, n;
    list<int> tamanhos;
    list<char> solucao;
    
    cin >> L;
    cin >> n;
    
    for(i = 0; i<n; i++) {
        int atual;
        cin >> atual;
        tamanhos.push_back(atual);
    }
    
    percorre(tamanhos, solucao, L, L);
    
    for(auto atual : solucaoFinal)
        cout << atual;
    cout << " (" << solucaoFinal.size() << ")" << endl;
    
    return 0;
}

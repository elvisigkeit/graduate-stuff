#include <iostream>
#include <list>
#include <unordered_set>
#include <set>
#include <string>

using namespace std;

set<string> palavras[10];

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

void procuraRetanguloMagico(list<string>& retangulo) {
    for(int prof = 9; prof >= 0; prof++)
    for (string str : palavras[prof]) {
        for (int i = 0; i < 10; i++)
            for (char c : str) {
                bool encontrado = false;
                for (string comp : palavras[i])
                    if (comp[prof] == c) {
                        encontrado = true;
                        break;
                    }
                if (!encontrado)
                    ;
            }
    }
}

void adicionaStringEmConjunto (string entrada) {
    if(entrada.length()>9) 
        return;
    
    palavras[entrada.length()-1].insert(entrada);
}

int main() {
    int n;
    string atual;
    list<string> retangulo;

    cin >> n;

    getline(cin, atual);
    for (int i = 0; i<n; i++){
        getline(cin, atual);
        adicionaStringEmConjunto(atual);
    }
    
    procuraRetanguloMagico();

    return 0;
}

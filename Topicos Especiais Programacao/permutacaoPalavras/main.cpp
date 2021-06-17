#include <iostream>
#include <list>
#include <string>

using namespace std;

void printaPermutacao(string permutacao) {
    cout << "- ";
    for(auto letra : permutacao)
        cout << letra;
    cout << endl;
}

bool ehVogal(char c) {
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' 
    || c == 'i' || c == 'I' || c == 'o' || c == 'O' 
    || c == 'u' || c == 'U')
        return true;
    return false;
}

bool palavraTemP(string& palavra) {
    bool resultado = false;
    for (auto letra : palavra)
        if(letra == 'p' ||  letra == 'P')
            resultado = true;
    return resultado;
}

bool palavraTemG(string& palavra) {
    bool resultado = false;
    for (auto letra : palavra)
        if(letra == 'g' ||  letra == 'g')
            resultado = true;
    return resultado;
}

bool validaString(string& palavra, char proximo) {
    if(palavra.length() == 0)
        if(ehVogal(proximo))
            return true;

    if(palavra.length()>1 &&
       !ehVogal(palavra[palavra.length()-1]) &&
       !ehVogal(palavra[palavra.length()-2]) &&
       !ehVogal(proximo)) 
       return false;

    if(proximo == 'P' || proximo == 'p')
        if(!palavraTemP(palavra) && palavraTemG(palavra)) 
            return false;

    if(palavra[palavra.length()-1] == proximo)
        return false;

    return true;
}

template<typename T>
void removePrimeiraOcorrencia (list<T>& lista, T valor) {
    for(auto it = lista.begin(); it!=lista.end(); it++)
        if (*it == valor) {
            lista.erase(it);
            return;
        }
}

void encontraConjuntos (list<char> restante, string& palavra) {
    if(restante.size() == 0) 
        printaPermutacao(palavra);

    for(char letra : restante) {
        if(validaString(palavra, letra)) {
            palavra += letra;
            list<char> novaLista(restante);
            removePrimeiraOcorrencia(novaLista, letra);
            encontraConjuntos(novaLista, palavra);
            palavra.pop_back();
        }
    }
}

list<char> criaListaDeString(list<char>& lista, string palavra) {
    for(auto letra : palavra)
        lista.push_back(letra);
    return lista;
}

int main () {
    string palavra;
    string permutacao;
    list<char> estado;
    cout << "Insira a palavra:" << endl;
    cin >> palavra;

    criaListaDeString(estado, palavra);

    encontraConjuntos(estado, permutacao);

    return 0;
}
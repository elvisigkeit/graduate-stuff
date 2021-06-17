#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
    Pessoa();
    Pessoa(string nome, string cpf, char sexo)
        : nome(nome), cpf(cpf), sexo(sexo) {};
    void print();
    
    string nome, cpf;
    char sexo;
private:
};

#endif
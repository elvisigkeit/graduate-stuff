#include "Pessoa.hpp"

Pessoa::Pessoa () {
    this->nome = "sem-nome";
    this->cpf = "11122233344";
    this->sexo = 'M';
}

void Pessoa::print() {
    cout << this->nome << " -> CPF: " 
        << this->cpf << " -> Sexo: " << 
        (this->sexo == 'M' ? "masculino." : "feminino.") << endl;
}
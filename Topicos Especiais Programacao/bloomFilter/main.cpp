#include "Pessoa.hpp"
#include <functional>
#include <math.h>

using namespace std;

class BloomFilter {
public:
    BloomFilter(double nrItems, double false_positive_probb) {
        this->size = getSizeOfFilter(nrItems, false_positive_probb);
        this->nrHashes = getNrHashes(nrItems);

        filter = new bool[this->size];
        for(unsigned i = 0; i < size; i++)
            filter[i] = false;

        cout << "\nBloomFilter criado! Com :"
            << "\nItens no filtro (esperados)       = " << nrItems
            << "\nProbabilidade de falsos positivos = " << false_positive_probb
            << "\nNúmero de bits no filtro          = " << this->size
            << "\nNúmero de funções hash            = " << this->nrHashes << '\n' << endl;
    }

    ~BloomFilter() {
        delete[] filter;
    }

    unsigned getSizeOfFilter (double nrItems, double prob) {
        double calc = nrItems * log(prob);
        calc /= log(1/ pow(2, log(2)));
        return ceil(calc);
    }

    unsigned getNrHashes (double nrItems) {
        double calc = (double) this->size / nrItems;
        calc *= log(2);
        return round(calc);
    }

    void add (Pessoa item) {
        for(unsigned i=0; i<nrHashes; i++) {
            unsigned hash = hashPessoa(item) ^
                            (std::hash<unsigned>()(i) << 16);
            unsigned index = hash % size;
            
            filter[index] = true;
        }
    }

    bool verify (Pessoa item) {
        for(unsigned i=0; i<nrHashes; i++) {
            unsigned hash = hashPessoa(item) ^
                            (std::hash<unsigned>()(i) << 16);
            unsigned index = hash % size;
            
            if(!filter[index])
                return false;
        }
        return true;
    }

    unsigned hashPessoa (Pessoa p) {
        return (std::hash<string>()(p.nome) ^ 
                std::hash<string>()(p.cpf) ^ 
                std::hash<char>()(p.sexo));
    }

    void verifyPessoa (Pessoa item) {
        if(verify(item))
            cout << (item.sexo == 'M' ? "O " : "A ")
                << item.nome << " pode estar na lista de pessoas marcadas." << endl;
        else
            cout << (item.sexo == 'M' ? "O " : "A ")
                << item.nome << " não está na lista de pessoas marcadas." << endl;
    }

    void printFilter () {
        cout << "Filter: ";
        for (unsigned i = 0; i < size; i++) {
            if(filter[i])
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

private:
    bool *filter;
    unsigned size;
    unsigned nrHashes;
};

int main () {
    Pessoa a("Joao", "12345678911", 'M');
    Pessoa b("Maria","12345678922", 'F');
    Pessoa c("José", "12345678933", 'M');

    a.print();
    b.print();
    c.print();

    BloomFilter bf(20, 0.001);

    bf.add(a);
    //bf.add(b);
    bf.add(c);

    bf.verifyPessoa(a);
    bf.verifyPessoa(b);
    bf.verifyPessoa(c);

    return 0;
}
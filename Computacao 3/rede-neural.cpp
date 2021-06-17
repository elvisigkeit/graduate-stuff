#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

template<int mantissa, int expoente>
class Sigmoid {
private:
	static constexpr double lambda = mantissa * pow(10, expoente);

public:
	double operator()(double x) {
		return 1.0 / (1.0 + exp(-lambda * x));
	}
};

template<typename FA>
class Camada {
public:
	Camada(int tamEntrada, int nNeuronios) :
			peso(nNeuronios, vector<double>(tamEntrada+1)) {
	}

	void avalia(const vector<double>& entrada, vector<double>& saida) {
		vector<double> somatorio(peso.size());

		for (int i=0; i<peso.size(); i++)
			somatorio[i] = peso[i][0];

		for (int i=0; i<peso.size(); i++)
			for (int j=1; j<peso[0].size(); j++)
				somatorio[i] += entrada[j-1]*peso[i][j];

		for (int i=0; i<peso.size(); i++)
			saida[i] = funcao(somatorio[i]);
	}

	void novosPesos(int neuronio, const vector<double>& p) {
		peso[neuronio] = p;
	}

	int numeroDeNeuronios() const {
		return peso.size();
	}
private:
	vector<vector<double> > peso;
	FA funcao;
};

template<typename FA>
class RedeNeural {
public:
	RedeNeural(int tamEntrada, vector<int> neuroniosPorCamada) {
		for (int i = 0; i < neuroniosPorCamada.size(); i++) {
			camada.push_back(Camada<FA>(tamEntrada, neuroniosPorCamada[i]));
			tamEntrada = neuroniosPorCamada[i];
		}
	}

	void avalia(const vector<double>& entrada, vector<double>& saida) {
		vector<double> entAtual = entrada;
		vector<double> saidAtual;
		for (auto& camadaAtual : camada) {
			saidAtual.resize(camadaAtual.numeroDeNeuronios());
			camadaAtual.avalia(entAtual, saidAtual);
			entAtual = saidAtual;
		}
		saida = saidAtual;
	}

	vector<double> operator()(const vector<double>& entrada) {
		int tamSaida = camada[camada.size() - 1].numeroDeNeuronios();
		vector<double> saida(tamSaida);

		avalia(entrada, saida);

		return saida;
	}

	void novosPesos(int camada, int neuronio, const vector<double>& p) {
		this->camada[camada].novosPesos(neuronio, p);
	}
	
private:
	vector<Camada<FA> > camada;
};

int main() {
//	Sigmoid<1, -1> s;
	vector<double> resultado(1);
	int primeiro = 1;

	RedeNeural<Sigmoid<1, -1> > rede(1, vector<int> (2, 1));
	rede.novosPesos(0, 0, vector<double> (3, 1.0));
	rede.novosPesos(1, 0, vector<double> (3, 3.0));
	rede.avalia(vector<double>(1,3.0), resultado);

	cout << "RESULTADO: (";
	for (auto& atual : resultado){
		if (primeiro)
			primeiro = 0;
		else
			cout << ", ";
		cout << atual;
	}
	cout << ")" << endl;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Vertice;

class Aresta {
public:
	Aresta(Vertice* a, Vertice* b) : origem(a), destino(b) {
		ehPonte = true;
	}
	bool ehPonte;
	Vertice* origem;Vertice* destino;
};

class Vertice {
public:
	Vertice(char a) : nome(a) {}

	void adicionaAresta(Aresta* aresta) {
		adjacentes.push_back(aresta);
	}

	char nome;
	vector<Aresta*> adjacentes;
};

class Grafo {
public:
	Grafo(char nrGrafo) {
		ifstream arqGrafos ("grafos");

		string linha;
		string grafoAtual = string("grafo ") + nrGrafo + ":";

		if (arqGrafos.is_open())
  		{
			char estado = 'a'; //modelarei os estados como a->grafo, b->vertices, c->arestas
   	 		while (getline(arqGrafos,linha)){
				switch(estado) {
					case  'a':
						if (linha == grafoAtual)
   	   						estado = 'b';
						break;
					case 'b':
						for(int i=0; linha[i] != '\0'; i++)
							if(linha[i] != ' ')
								vertices.push_back(Vertice(linha[i]));
						estado = 'c';
						break;
					case 'c':
						if(linha[0] == '\0'){
							estado = 'd';
							break;
						}

						Vertice* a = ponteiroPorNome(linha[0]);
						Vertice* b = ponteiroPorNome(linha[2]);
						if (a == nullptr || b == nullptr) {
							cerr << "ACESSO ERRADO NA ARESTA" << endl;
							exit (3);
						}
						Aresta* novaAresta = new Aresta(a, b);
						arestas.push_back(novaAresta);

						(*a).adicionaAresta(novaAresta);
						(*b).adicionaAresta(novaAresta);
				}
   	 		}
			if (estado == 'a') {
				cerr << "GRAFO NAO ENCONTRADO NO ARQUIVO!" << endl;
				exit(1);
			}
    		arqGrafos.close();
  		}
	}

	Vertice* ponteiroPorNome (char nome) {
		int indice = nome - 'A';

		if (vertices[indice].nome == nome)
			return &(vertices[indice]);

		for(indice=0; indice<(int)vertices.size(); indice++)
			if (vertices[indice].nome == nome)
				return &(vertices[indice]);

		return nullptr;
	}

	void print () {
		for (auto atual : vertices) { 
			cout << "[" << atual.nome << "] ";
			for (auto adj : atual.adjacentes)
				if ((*adj).destino->nome == atual.nome)
					cout << "->" << (*adj).origem->nome << ' ';
				else
					cout << "->" << (*adj).destino->nome << ' ';
			cout << endl;
		}
	}

	~Grafo() {
		for (auto atual : arestas)
			delete atual;
	}

	vector<Vertice> vertices;
	vector<Aresta*> arestas;
};

int main (int argc, char** argv) {
	if (argc != 2){
		cerr << "PROGRAMA SEM ENTRADA!" << endl;
		exit(2);
	}

	char nrGrafo = argv[1][0];

	Grafo grafo(nrGrafo);
	grafo.print();
}

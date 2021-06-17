#include <iostream>
#include <vector>

class Grafo 
{

private:
	vector<Vertice> vertices;
	vector<Arestas> arestas;
};

class Vertice
{
public:
	Vertice(vector<Aresta> vecA) {
		arestas = vecA;
	}

private:
	char nome;
	vector<Aresta> arestas;
};

class Aresta
{
public:
	Aresta() { destino = NULL; }
	Aresta( Vertice* novo ) {
		destino = novo;
	}

	Vertice *destino;
};

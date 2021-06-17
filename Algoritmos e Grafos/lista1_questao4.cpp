#include <iostream>
#include <vector>

using namespace std;

class Vertice {
public:
	Vertice(string palavra)
	: palavra(palavra){};

	string palavra;
	vector<Vertice*> adjacentes;
	int indice;
};

class Grafo {
public:
	Grafo () : head(26) {}
	
	Grafo(Vertice *entrada) : head(26) {
		adicionaVertice(entrada->palavra);
		delete entrada;
	}

	~Grafo() {
		for (auto atual : vertices)
			delete atual;
	}

	void adicionaVertice (const string& str) {
		Vertice* novoVertice = new Vertice(str);

		int indiceh = str.front() - 'a';
		head[indiceh].push_back(novoVertice);

		novoVertice->indice = vertices.size();
		vertices.push_back(novoVertice);
	}

	void geraLigacoes() 
	{
		for (auto atual : vertices)
		{
			int indice = atual->palavra.back() - 'a';
			atual->adjacentes = head[indice];
		}
		//possivelmente destroi o vetor de heads;
	}

	int nrVertices () {
		return vertices.size();
	}

	bool buscaCaminho(int inicio)
	{
		int *pai = new int[vertices.size()];
		for (unsigned i=0; i<vertices.size(); i++)
			pai[i] = -1;
		pai[inicio] = inicio;
		bool completo = 0;
		int restantes = vertices.size() - 1;
		listaFinal.push_back(vertices[inicio]);
		for (auto atual : vertices[inicio]->adjacentes){
			restantes--;
			if (pai[atual->indice] != -1)
				continue;
			pai[atual->indice] = inicio;
			listaFinal.push_back(atual);
			if(!restantes){
				completo = 1;
				break;
			}
			
			completo = buscaCaminho(atual->indice, restantes, pai);
			if (completo){
				break;
			}
			listaFinal.pop_back();
		}
		
		if (!completo)
			listaFinal.pop_back();


		delete[] pai;
		return completo;
	}

	bool buscaCaminho(int indice, int restantes, int* pai)
	{

		for (auto atual : vertices[indice]->adjacentes) 
		{
			if (pai[atual->indice] != -1)
				continue;
			pai[atual->indice] = indice;

			listaFinal.push_back(atual);
			restantes--;
			if (!restantes)
				return 1;

			if (buscaCaminho(atual->indice, restantes, pai))
				return 1;
			listaFinal.pop_back();
		}
		
		return 0;
	}

	void printaGrafo () {
		
		cout << "\nPRINT DO GRAFO" << endl;

		for (auto vertice : vertices) 
		{
			cout << "\nVERTICE " << vertice->palavra << endl << "    ";
			for (auto adjacente : vertice->adjacentes) 
				cout << "-> " << adjacente->palavra << " ";
			cout << endl;
		}
	}

	void printaResultado() {
		if (!listaFinal.size()){
			cout << "-1" << endl;
			return ;
		}
		
		cout << endl;
		for (auto atual : listaFinal)
			cout << atual->palavra << endl;

		cout << endl;
	}
	

	vector<Vertice*> listaFinal;
	vector<Vertice*> vertices;
	vector< vector<Vertice*> > head;
};



int main () 
{
	Grafo grafo;

	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		string atual;
		cin >> atual;
		grafo.adicionaVertice(atual);
	}


	grafo.geraLigacoes();
	for (int i=0; i<grafo.nrVertices(); i++) 
		if(grafo.buscaCaminho(i))
			break;
	

	grafo.printaResultado();

	return 0;
}

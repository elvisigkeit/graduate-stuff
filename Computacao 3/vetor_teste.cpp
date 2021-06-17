#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <int n, typename T>
class VetorIntermediario;

template <int n, typename T>
class Vetor
{
public:
	Vetor<n, T> () { if (n<=0) exit(1); } //erro da criacao nula ou negativa
	
//	Vetor<n, T> (Vetor<n, T>&& entrada) {
//		for (int i=0; i<n; i++)
//			vetor[i] = entrada[i];
//	}
	
	Vetor<n, T> (Vetor<n, T>& entrada) {
		for (int i=0; i<n; i++)
			vetor[i] = entrada[i];
	}


	Vetor& operator= (Vetor entrada) {
		for (int i=0; i<n; i++)
			vetor[i] = entrada[i];
		return *this;
	}

	VetorIntermediario<n, T>& operator= (T entrada) {
		vetor[0] = entrada;
		VetorIntermediario<n, T>* saida = new VetorIntermediario<n, T>(this);
		return *saida;
	}
	
	T operator[] (const int entrada) const{
		if (entrada >= n)
			exit (2); //erro do acesso [] excedente
		return vetor[entrada];
	}

	T& operator[] (int entrada) {
		if (entrada >= n)
			exit (2); //erro do acesso [] excedente
		return vetor[entrada];
	}

	T operator* (Vetor entrada) {
		int resultado = 0;
		for (int i=0; i<n; i++)
            resultado += (vetor[i] * entrada[i]);
        return resultado;
    }

	Vetor<3, T> operator* (VetorIntermediario<n, T> entrada) {
		if (n == 1 || n>3)
			exit (4); //erro de determinante desconhecido
		if (n == 2) {
			Vetor<3, T> resultado;
			resultado = 0, 0, 0;
			Vetor<n, T>* ent = entrada.vetor;
			resultado[2] = vetor[0]*(*ent)[1] - vetor[1]*(*ent)[0];
			return resultado;
		}
		//if (n==3)
		Vetor<3, T> resultado;
		Vetor<n, T>* ent = entrada.vetor;
		resultado[0] = vetor[1]*(*ent)[2] - vetor[2]*(*ent)[1];
		resultado[1] = vetor[2]*(*ent)[0] - vetor[0]*(*ent)[2];
		resultado[2] = vetor[0]*(*ent)[1] - vetor[1]*(*ent)[0];
		return resultado;
	}

	VetorIntermediario<n, T> operator* () {
		return VetorIntermediario <n, T> (this);
	}

private:
	T vetor[n];
};

template <int n, typename T>
Vetor<n, T> operator- (const Vetor<n, T>& a,const Vetor<n, T>& b) {
	Vetor<n, T> auxiliar;
	for (int i=0; i<n; i++)
		auxiliar[i] = a[i] - b[i];
	return auxiliar;
}

template <int n, typename T>
Vetor<n, T> operator+ (const Vetor<n, T>& a,const Vetor<n, T>& b) {
	Vetor<n, T> auxiliar;
	for (int i=0; i<n; i++)
		auxiliar[i] = a[i] + b[i];
	return auxiliar;
}
	

template <int n, typename T>
Vetor<n, T> operator* ( const T a,const Vetor<n, T>& b) {
	Vetor<n, T> auxiliar;
	for (int i=0; i<n; i++)
		auxiliar[i] = a * b[i];
	return auxiliar;
}

template <int n, typename T>
Vetor<n, T> operator* (const Vetor<n, T>& a,const T& b) {
	Vetor<n, T> auxiliar;
	for (int i=0; i<n; i++)
		auxiliar[i] = a[i]*b;
	return auxiliar;
}

template <int n, typename T>
Vetor<n, T> operator/ (const Vetor<n, T>& a,const T& b) {
	Vetor<n, T> auxiliar;
	for (int i=0; i<n; i++)
		auxiliar[i] = a[i]/b;
	return auxiliar;
}

template <int n, typename T>
class VetorIntermediario 
{
public:
	VetorIntermediario(Vetor<n, T>* entrada) {
		vetor = entrada;
		atual = 1;
	}

	VetorIntermediario& operator , (T entrada) {
		if (atual >= n)
			exit(3); //erro da virgula excedente
		(*vetor)[atual++] = entrada;
		if (atual == n)
			delete this;
		return *this;
	}

	Vetor<n, T>* vetor;
private:
	int atual; //inteiro relacionado a atribuicao sequencial
};

template<int n, typename T>
inline ostream& operator<< (ostream& o, Vetor<n, T>& entrada)
{
	o << "[";
	for (int i=0; i < n; i++) {
		if (i != n-1)
			o << entrada[i] <<  ", ";
		else
			o << entrada[i];
	}
	o << "]";

	return o;
}

int main () {
	Vetor <2, int> b;

	b = 0, 1;
	Vetor <2, int> a(b);
	a = 1, 0;

	cout << "] A inicial       - " << a << endl;

	a = a + b - b;

	cout << "] A transformado  - " << a << endl;

	a = 2*a*1;

	cout << "] 2*A             - " << a << endl;
	
	a = (2*a)/2;

	int escalar = a * a;

	cout << "] A*A             - " << escalar << endl;

	Vetor<3, int> vetorial;

	vetorial = a ** b;

	cout << "] A**B            - " << vetorial << endl;

	Vetor<3, double> a3, b3;
	Vetor<3, double> vetorial3;

	a3 = 1, 2, 3;
	b3 = 2, 3, 4;
	
	vetorial3 = a3 ** b3;

	cout << "] A3**B3          - " << vetorial3 << endl;

	return 0;
}

#include <iostream>
#include <string>


using namespace std;

class Data{
public:
	string dataCurta() {
		return "oi";
	}
};

template <typename T>
class AutoRef {
public:
	AutoRef() : ponteiro(NULL) {
		contador = new int;
		*contador = 0;
	}

	~AutoRef() {desreferencia();}

	T& operator * () const {
		return *ponteiro;
	}

	T* operator -> () const {
		return ponteiro;
	}

	T* operator = (T* entrada) {
		desreferencia();
		ponteiro = entrada;
		contador = new int;
		*contador = 0;
		referencia();
		return entrada;
	}

	AutoRef& operator = (const AutoRef& entrada) {
		desreferencia();
		ponteiro = entrada.ponteiro;
		if (ponteiro){
			contador = entrada.getContador();
			referencia();
		}
		return *this;
	}

	int* getContador() const { return contador; }

private:
	void desreferencia() {
		(*contador)--;
		if (*contador <= 0){
			delete ponteiro;
			delete contador;
		}
	}

	void referencia() {
		(*contador)++;
	}

	T* ponteiro;
	int* contador;
};

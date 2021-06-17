#include <string>

using namespace std;

struct Lista {
  bool sublista;
  string valorString;
  Lista* valorSublista;
  Lista* proximo;
};

Lista* geraLista() {
	Lista* l0 = new Lista();
	Lista* l1 = new Lista();
	Lista* l2 = new Lista();
	Lista* l3 = new Lista();
	Lista* l4 = new Lista();
	Lista* l5 = new Lista();
	Lista* l6 = new Lista();
	Lista* l7 = new Lista();
	Lista* l8 = new Lista();
	Lista* l9 = new Lista();
	Lista* l10 = new Lista();
	Lista* l11 = new Lista();
	Lista* l12 = new Lista();

	l0->sublista = false;
	l0->valorString = "y";
	l0->valorSublista = nullptr;
	l0->proximo = nullptr;
	l1->sublista = true;
	l1->valorSublista = 	l0;
	l1->proximo = 	l5;

	l2->sublista = false;
	l2->valorString = "i";
	l2->valorSublista = nullptr;
	l2->proximo = nullptr;
	l3->sublista = true;
	l3->valorSublista = 	l2;
	l3->proximo = 	l4;

	l4->sublista = false;
	l4->valorString = "8";
	l4->valorSublista = nullptr;
	l4->proximo = nullptr;
	l5->sublista = true;
	l5->valorSublista = 	l3;
	l5->proximo = 	l11;

	l6->sublista = true;
	l6->valorSublista = nullptr;
	l6->proximo = nullptr;
	l7->sublista = true;
	l7->valorSublista = 	l6;
	l7->proximo = 	l8;

	l8->sublista = true;
	l8->valorSublista = nullptr;
	l8->proximo = 	l10;

	l9->sublista = false;
	l9->valorString = "9";
	l9->valorSublista = nullptr;
	l9->proximo = nullptr;
	l10->sublista = true;
	l10->valorSublista = 	l9;
	l10->proximo = nullptr;
	l11->sublista = true;
	l11->valorSublista = 	l7;
	l11->proximo = 	l12;

	l12->sublista = false;
	l12->valorString = "9.7";
	l12->valorSublista = nullptr;
	l12->proximo = nullptr;

	return 	l1;
}


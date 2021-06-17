#include <iostream>
#include <string>

using namespace std;

struct Lista {
  bool sublista; 
  string valorString;
  Lista* valorSublista;
  Lista* proximo;  
};

extern Lista* geraLista();

string print( Lista* l ) {
    string result;
    
    if( l != nullptr ) {
      if( l->sublista ) 
        result = "( " + print( l->valorSublista ) + " )";
      else
	      result = l->valorString;
      
      if( l->proximo != nullptr )
        result += ", " + print( l->proximo );
    }

    return result;
}

void limpa_lista(Lista* lista) {
  if(!lista) return;
  
  Lista* prox = lista->proximo;
  Lista* subprox = lista->valorSublista;
  
  limpa_lista(prox);
  limpa_lista(subprox);

  free(lista);
}


int main() {   
    Lista *lista = geraLista();
    cout << print( lista ) << endl;
    limpa_lista( lista );
    return 0;
}
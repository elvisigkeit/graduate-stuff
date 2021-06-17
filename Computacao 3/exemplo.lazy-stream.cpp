#include <iostream>
#include <vector>

using namespace std;

template <typename Base, typename TipoIterador, typename Predicado>
class Iterador {
public:
  Iterador( TipoIterador v, Predicado p ) : v(v), predicado( p ) {}
  
  Iterador& begin() {
    atual = v.begin();
    while( atual != v.end() && predicado( *atual ) == false )
      ++atual;
    
    return *this;
  }
  
  Iterador& end() {
    return *(Iterador*) nullptr;
  }
  
  bool operator != ( const Iterador& itr ) {
    return *this->atual != *itr.atual; 
  }
  
  void operator ++ () {    
    ++atual;
    while( atual != v.end() && predicado( *atual ) == false )
      ++atual;
  }
  
  Base operator * () {
    return *atual;
  }
  
private:
  Predicado predicado;
  TipoIterador v;
  typename TipoIterador::iterator atual;
};

int main( int argc, char* argv[] ) {
  vector<int> v;
 
  v.push_back( 1 );
  v.push_back( 2 );
  v.push_back( 3 );
  
  auto predicado = []( int x ){ return x % 2 == 0; };
  Iterador< int, vector<int>, decltype( predicado ) > p{ v, predicado };
  int i = 0;
  for( auto itr = p.begin(); itr != p.end() && i<10; ++itr, i++ )
    cout << *itr << endl;
   
  cout << endl;
  return 0;
}

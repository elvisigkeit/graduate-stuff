#include <iostream>
#include <vector>

using namespace std;

template <typename E, typename T>
struct RetornoBool {
};

template<typename T>
struct RetornoBool<bool, T> {
  typedef vector<T> Tipo;
};

template <typename E, typename T>
struct RetornoVoid {
};

template<typename T>
struct RetornoVoid<void, T> {
  typedef void Tipo;
};

template <typename E, typename T>
struct RetornoResto {
  typedef vector<T> Tipo;
};

template<typename T>
struct RetornoResto<bool, T> {
};

template<typename T>
struct RetornoResto<void, T> {
};

template <typename TipoIterador, typename Predicado>
class Iterador {
public:
  Iterador( TipoIterador v, Predicado p ) : predicado( p ), v(v) {
  	begin();
	fim = end();
  }
    
  Iterador& begin() {
    atual = v.begin();
    while( predicado( *atual ) == false ){
      ++atual;
      if (atual == v.end())
                break; 
    }
    return *this;
  }
          
  typename TipoIterador::iterator end() {
    return v.end();
  }
      
  bool operator != ( const typename TipoIterador::iterator itr ) {
    return atual != itr; 
  }
          
  void operator ++ () {
    ++atual;
    while( atual != fim && predicado( *atual ) == false )
      ++atual;
  }
           
  auto operator * () -> decltype ( **((typename TipoIterador::iterator*) nullptr)) {
    return *atual;
  }
                          
private:
  Predicado predicado;
  TipoIterador v;
  typename TipoIterador::iterator atual;
  typename TipoIterador::iterator fim;
};


template <typename T, typename F>
auto operator | ( T v, F f ) 
  -> typename RetornoBool<decltype( f( *v.begin() ) ), 
                          typename T::value_type>::Tipo {
  vector<typename T::value_type> result;
  
  for( auto x : v )
    if( f( x ) )
      result.push_back( x );
  
  return result;
}

template <typename T, typename F>
auto operator | ( T v, F f ) 
  -> typename RetornoResto<decltype( f( *v.begin() ) ), 
                           decltype( f( *v.begin() ) )>::Tipo {
  vector<decltype( f( *v.begin() ) )> result;
  
  for( auto x : v )
    result.push_back( f( x ) );
  
  return result;
}



template <typename T, typename F>
auto operator | (T v, F f)
	-> typename RetornoVoid<decltype( f( *v.begin() ) ),
							typename T::value_type>::Tipo{
  for (auto atual : v)
  	f(atual);
}



int main( int argc, char* argv[] ) {
  vector<int> v;
  v.push_back( 1 );
  v.push_back( 2 );
  v.push_back( 3 );
  v.push_back( 4 );
  v.push_back( 0 );
                      
  auto predicado = []( int x ){ return x % 2 == 0; };
  Iterador< vector<int>, decltype( predicado ) > p{ v, predicado };
  
      v | [] ( int x ) { return x % 2 == 0; } 
        | [] ( int x ) { return x*x / 10.0; } 
        | [] ( int x ) { cout << x << endl; };

 for ( auto itr = p.begin(); itr != p.end(); ++itr ){
   cout << *itr << endl;
 }
                                         
 cout << endl;
 return 0;
 
 }


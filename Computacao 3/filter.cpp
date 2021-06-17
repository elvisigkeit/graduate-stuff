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
auto operator | ( T v, F f ) 
  -> typename RetornoVoid<decltype( f( *v.begin() ) ), 
                             typename T::value_type>::Tipo {
  for( auto x : v )
    f( x );
}

template <typename T, typename F, int N>
void operator | ( T(& t)[N], F f ) {
  for( int i = 0; i < N; i++ )
    f( t[i] );
}

int main( int argc, char* argv[] ) {
  int tab[10] =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  vector<int> v;
  
  tab |	 [ &v ]( int x ) { v.push_back( x ); };
  v | []( int x ) { return x % 2 == 0; } 
    | []( int x ) { return x*x / 10.0; } 
    | [] ( double x ) { cout << x << endl; };
   
  cout << endl;
  return 0;
}

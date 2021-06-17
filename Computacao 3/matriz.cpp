#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

const int NR_THREADS	=	8;
const int TAM		=	1000; 

double a[TAM][TAM];
double b[TAM][TAM];
double c[TAM][TAM];

void inicializa( double m[TAM][TAM] ) {
  for( int i = 0; i < TAM; i++ )
    for( int j = 0; j < TAM; j++ )
      m[i][j] = rand() / (double) RAND_MAX;
}

void multiplica( double ma[TAM][TAM], double mb[TAM][TAM], double mc[TAM][TAM], int thread ) {
  int limSuperior = (TAM/NR_THREADS)*(thread+1);
  int limInferior = (TAM/NR_THREADS)*(thread);
  if (thread==NR_THREADS)
  	limSuperior = TAM;

  for( int i = limInferior; i < limSuperior; i++ )
    for( int j = 0; j < TAM; j++ )
      mc[i][j] = 0;
  for( int i = limInferior; i < limSuperior; i++ )
	for( int k = 0; k < TAM; k++ )
      for( int j = 0; j < TAM; j++ )
        mc[i][j] += ma[k][j] * mb[i][k];
}

using namespace std;

int main() {
  thread th[NR_THREADS];

  using namespace std::chrono;

  srand( time(NULL) );
  
  steady_clock::time_point t1 = steady_clock::now();
  
  inicializa(a);
  inicializa(b);

  for (int i = 0; i < NR_THREADS; i++)
    th[i] = thread(multiplica, a, b, c, i);
  
  for (int i = 0; i < NR_THREADS; i++)
    th[i].join();

  steady_clock::time_point t2 = steady_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  cout << time_span.count() << endl;

  for (int i = 0; i < TAM; i++)
    cout << c[i][0] << " ";
  cout << endl;

  return 0;
}

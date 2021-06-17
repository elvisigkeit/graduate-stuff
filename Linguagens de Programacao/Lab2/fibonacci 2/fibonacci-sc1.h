/*
Arquivo de protótipos do programa principal da fibonacci
Autor : Elvis Nobrega
*/
#ifndef FIB_H
#define FIB_H

class Fibonacci {
	public:
		int getResultado();
		void computaFibonacci(int );
	private:
		int resultado;
		int geraResultado (int );
};

#endif

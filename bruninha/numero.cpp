#include <iostream>
#include <iomanip>
#define PI 3.14159


using namespace std;

int main(){
	//define as variaveis 
	double area, raio;
	cin >> raio;
	area = PI*raio*raio;
	
	//mostra a área
	cout << "A=" << fixed << setprecision(4) << area  << endl;

	return 0;
}

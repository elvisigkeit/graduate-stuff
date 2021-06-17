#include <iostream>
#include <iomanip>

using namespace std;

int main() {
//cria as variaveis
	double a, b, c, areaTriangulo, pi, areaCirculo, areaTrapezio, areaQuadrado, areaRetangulo;
//pega as variaveis
	cin >> a >> b >> c;
//calcula as variaveis
	areaTriangulo = (a*c)/2;
	pi = 3.14159;
	areaCirculo = pi*c*c;
	areaTrapezio = ((b + a)*c)/2;
	areaQuadrado = b*b;
	areaRetangulo = a*b;
//mostra os valores
	cout << "TRIANGULO: " << fixed << setprecision(3) << areaTriangulo << endl;
	cout << "CIRCULO: " << fixed << setprecision(3) << areaCirculo << endl;
	cout << "TRAPEZIO: " << fixed << setprecision(3) << areaTrapezio << endl;
	cout << "QUADRADO: " << fixed << setprecision(3) << areaQuadrado << endl;
	cout << "RETANGULO: " << fixed << setprecision(3) << areaRetangulo << endl;
	return 0;
}

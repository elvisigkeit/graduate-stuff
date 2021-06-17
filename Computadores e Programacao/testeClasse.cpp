#include <iostream>

class Vetor 
{
	private:
	int x, y;
	
	public:

	Vetor (int a, int b)
	{
		x = a; y = b;
	}

	int getX() { return x; }
	int getY() { return y; }
};


using namespace std;

int main ()
{
	Vetor v(12, 13);
	cout << "Vetor: " << v.getX() << ", " << v.getY();
	return 0;
}

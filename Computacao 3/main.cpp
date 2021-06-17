#include "Vector.h"

int main () {
	Vector a(3);
	a.print(std::cout);
	try{ 
		std::cout << a[5] << std::endl;
	}catch(const std::out_of_range& oor) {
		std::cout << oor.what() << std::endl;
	}

	return 0;
}		

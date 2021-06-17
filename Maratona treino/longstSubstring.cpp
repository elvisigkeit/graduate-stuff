#include <iostream>
#include <string>

using namespace std;

int main () {
	string str1, str2;
	unsigned int i, j, maxSubstr = 0;
	
	cin >> str1;
	cin >> str2;

	unsigned int array1[str2.size()], array2[str2.size()];
	
	unsigned int *aux = NULL, *atual = &(array1[0]), *anterior = &(array2[0]);

	for (i = 0; i<str1.size(); i++) {
		for (j = 0; j<str2.size(); j++) {
			
			if (i == 0)
				anterior[j] = 0;

			if (str1[i] != str2[j])
				atual[j] = 0;
			
			else {
				if (i == 0 || j == 0) 
					atual[j] = 1;
				else
					atual[j] = 1 + anterior[j-1];

				if (atual[j]>maxSubstr)
					maxSubstr = atual[j];
			}
		} 
		aux = atual;
		atual = anterior;
		anterior = aux;
	}

	cout << "Maior substring: " << maxSubstr << endl;

	return 0;
}

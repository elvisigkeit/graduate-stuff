#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main () {
	string str1, str2;
	unsigned int primeiras = 0, ultimas = 0, fim;
	unsigned int tamLCS = 0;

	cin >> str1;
	cin >> str2;

	fim = min(str1.length(), str2.length());

	while(str1[primeiras]==str2[primeiras] && primeiras<fim){
		tamLCS++; primeiras++;
	}

	unsigned int tam1 = str1.length(), tam2 = str2.length();

	while((str1[tam1-ultimas]==str2[tam2-ultimas]) && ((tam1-ultimas)>primeiras) && ((tam2-ultimas)>primeiras)){
		ultimas++; tamLCS++;
		str1.pop_back(); str2.pop_back();
	}

	str1.erase(0, primeiras);
	str2.erase(0, primeiras);

	

	cout << "Tamanho da LCS = " << tamLCS << endl;

	return 0;
}	

#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	int M = (int)(argv[1][0] - '0');
	int N = (int)(argv[2][0] - '0');
	int i, j, k, tamX, tamY;
	vector< vector<int> > Matrix(N, vector <int> (M, -1));
	tamX = Matrix.size();
	for (i = 0; i < tamX; i++){
		tamY = Matrix[i].size();
		for(j = 0; j < tamY; j++){
			for (k = 0; k<2&&j!=0; k++)
				cout << " ";
			cout << Matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}

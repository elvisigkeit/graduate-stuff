#include <bits/stdc++.h>

struct Point {
	Point (int a = 0,int b = 0) {x = a; y = b;}
	Point (int a, int b, char n) {x = a; y = b; name = n;}
 
	Point operator+ (Point right) {return Point(x+right.x, y+right.y);}
	Point operator- (Point right) {return Point(x-right.x, y-right.y);}

	int operator* (Point right) {return x*right.x + y*right.y;}
	int operator/ (Point right) {return x*right.y - y*right.x;}

	bool operator< (Point right) {return x<right.x ? true : y<right.y ? true : false;}
		
	char name;
	int x, y;
};

typedef Point Vetor;

using namespace std;

int main (int argc, char** argv) {
/*	Point teste1(atoi(argv[1]), atoi(argv[2]), argv[3][0]);
	Point teste2(atoi(argv[4]), atoi(argv[5]), argv[6][0]);*/

	int nrPoints, i;
	cin >> nrPoints;

	Point vecPoints[nrPoints];
	for (i = 0; i<nrPoints; i++)
		cin >> vecPoints[i].x >> vecPoints[i].y >> vecPoints[i].name;

	return 0;
}

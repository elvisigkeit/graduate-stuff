#include <bits/stdc++.h>

struct Point {
	Point (int a = 0,int b = 0) {x = a; y = b;}
	Point (int a, int b, char n) {x = a; y = b; name = n;}
 
	Point operator+ (Point right) {return Point(x+right.x, y+right.y);}
	Point operator- (Point right) {return Point(x-right.x, y-right.y);}
	void operator= (Point right) {x = right.x; y = right.y; name = right.name;}

	int operator* (Point right) {return x*right.x + y*right.y;}
	int operator/ (Point right) {return x*right.y - y*right.x;}

	bool operator< (Point right) const {
		if (y<right.y)
			return true;
		if (y == right.y && x<right.x) 
			return true;
		return false;
	}
		
	char name;
	int x, y;
};

typedef Point Vetor;

using namespace std;

Point Pivot;

int dist (Point a, Point b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int CCW (Point a, Point b, Point c) {
	int ccw = a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
	if (ccw > 0) return 1;
	if (ccw == 0) return 0;
	return -1;
}

bool cmpPoints (Point a, Point b) {
	
	if (CCW(Pivot, a, b) == 0)
		return (dist(Pivot, a)<dist(Pivot, b));
	
	return (CCW(Pivot, a, b)>0);
}

int main (int argc, char** argv) {
/*	Point teste1(atoi(argv[1]), atoi(argv[2]), argv[3][0]);
	Point teste2(atoi(argv[4]), atoi(argv[5]), argv[6][0]);
	Point teste3(atoi(argv[7]), atoi(argv[8]), argv[9][0]);

	cout << "CCW : " << CCW(teste1, teste2, teste3) << endl;
*/

	int nrPoints, i;
	cin >> nrPoints;

	Point vecPoints[nrPoints];
	for (i = 0; i<nrPoints; i++)
		cin >> vecPoints[i].x >> vecPoints[i].y >> vecPoints[i].name;

	int pivot = 0;
	for (i = 0; i<nrPoints; i++)
		if(vecPoints[i]<vecPoints[pivot])
			pivot = i;
	
	Point aux = vecPoints[0];
	vecPoints[0] = vecPoints[pivot];
	vecPoints[pivot] = aux;
		
	Pivot = vecPoints[0];

	sort(vecPoints+1, vecPoints+nrPoints, cmpPoints);

	vector <Point> cHull;

	for (i = 0; i<nrPoints; i++){
		unsigned size = cHull.size();

		/*cout << "Giro " << i << " do codigo:" << endl;
		for (Point atual : cHull)
			cout << atual.name << " ";*/
		
		while (size>1 && (CCW(cHull[size-2], cHull[size-1], vecPoints[i])<=0)){
			cHull.pop_back();
			size = cHull.size();
		}
		
		cHull.push_back(vecPoints[i]);
	}

	for (Point atual : cHull)
		cout << atual.name << " " << endl;

	return 0;
}

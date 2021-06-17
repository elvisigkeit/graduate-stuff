#include <iostream>
#include <vector>
#include <functional>

using namespace std;
/*
template <typename T, int n, class Function>
vector<T> operator|(T(& t)[n], const Function func) {
	vector<T> result;
	for (int i=0; i<n; i++)
		if (func(t[i]))
			result.push_back(t[i]);
	return result;
}
 
template <typename T, class Function>
vector<T> operator|(vector<T> vec, const Function func) {
	vector<T> result;
	for (T i : vec)
		if (func(i))
			result.push_back(i);
	return result;
}*/



template <typename T, int n, class Function>
void operator|(T(& t)[n], const Function func) {
	for (int i=0; i<n; i++)
		func(t[i]);
}
 
template <typename T, class Function>
void operator|(vector<T>& vec, const Function func) {
	for (T i : vec)
		func(i);
}

template <typename T>
template <T, decltype([](T)->bool{})>
vector<T> operator|(vector<T> vec, const Function func){
	for (T i : vec)
		func(i);
}

int main () {
	int tab[10] =  { 1, 2, 3, 2, 3, 4, 6, 0, 1, 8 };
	vector<int> v;
	tab | []( int x ) { cout << x*x << endl; };
	tab | [ &v ]( int x ) { v.push_back( x ); return false; };
	v | []( int x ) { cout << x*x << endl; };
//	v | []( int x ) { return x % 2 == 0; } | [] ( int x ) { cout << x << endl; };

	return 0;
}

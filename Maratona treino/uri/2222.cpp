#include <bits/stdc++.h>

using namespace std;

/*
int operation (int choice, set<int> a, set<int> b) {
	cout << "operacao " << choice << endl;
	if (choice == 1){
		int result=0;
		for (set<int>::iterator it=b.begin(); it!=b.end(); it++)
			result+=a.count(*it);
		cout << " resultado " << result << endl;
		return result;
	}
	for (set<int>::iterator it=b.begin(); it!=b.end(); it++)
		a.insert(*it);
	cout << " resultado " << a.size() << endl;
	return a.size();
}*/

int main () {
	int nrSets, operations, i;

	cin >> nrSets;

	set <int> sets[nrSets];

	for (i = 0; i < nrSets; i++){
		int nrEle;
		cin >> nrEle;
		while (nrEle>0){
			int novo;
			cin >> novo;
			sets[i].insert(novo);
			nrEle--;
		}
	}

	cin >> operations;
	int results[operations];
	
	for (i = 0; i<operations; i++){
		int choice, a, b;
		cin >> choice >> a >> b;
		a--; b--;
		cout << "atual :" << a << b << endl;
//		results[i] = operation (choice, sets[a], sets[b]);
		cout << "operacao " << choice << endl;
		if (choice == 1){
			int result=0;
			for (set<int>::iterator it=b.begin(); it!=b.end(); it++)
				result+=a.count(*it);
			cout << " resultado " << result << endl;
			results[i] = result;
		}
		for (set<int>::iterator it=b.begin(); it!=b.end(); it++)
			a.insert(*it);
		cout << " resultado " << a.size() << endl;
		results[i] = a.size();
	}

	for (int a: results)
		cout << a;

	return 0;
}

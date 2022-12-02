#include <bits/stdc++.h>
 
using namespace std;
 
int polyhedra(string s) {
	if(s == "Tetrahedron") {
		return 4;
	} else if(s == "Cube") {
		return 6;
	} else if(s == "Octahedron") {
		return 8;
	} else if(s == "Dodecahedron") {
		return 12;
	} else {
		return 20;
	}
}
 
int main() {
	int sum, n;
	string s;
	sum = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		sum += polyhedra(s);
	}
	cout << sum;
	
	return 0;
}        
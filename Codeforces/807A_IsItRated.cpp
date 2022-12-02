#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	bool sorted = true; 
	bool change = false;
	int n, a1, b1, a2, b2;
	cin >> n;
	cin >> a1 >> b1;
	if(a1 != b1) {
		cout << "rated";
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		cin >> a2 >> b2;
		if(a2 > a1) {
			sorted = false;
		}
		if(a2 != b2) {
			cout << "rated";
			return 0;
		}
		a1 = a2;
		b1 = b2;
	}
	if(sorted) {
		cout << "maybe";
	} else {
		cout << "unrated";
	}
}        
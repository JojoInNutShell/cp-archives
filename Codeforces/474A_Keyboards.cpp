#include <bits/stdc++.h>
 
using namespace std;

set<int> a;
 
int main() {
	int n, t, temp;
	cin >> n;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		cin >> temp;
		a.insert(temp);
	}
	cin >> t;
	for(int i = 0; i < t; ++i) {
		cin >> temp;
		a.insert(temp);
	}
	
	if(n == a.size()) {
		cout << "I become the guy.";
	} else {
		cout << "Oh, my keyboard!";
	}
}        
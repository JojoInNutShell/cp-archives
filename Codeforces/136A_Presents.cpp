#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	array<int, 103> a;
	int n, t;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> t;
		a[t] = i;
	}
	for(int i = 1; i <= n; ++i) {
		cout << a[i] << " ";
	}
}
#include <bits/stdc++.h>
 
using namespace std;

void addzero(int n) {
	for(int i = 0; i < n; ++i) {
		cout << 0;
	}
	return;
}
 
int main() {
	int n, t;
	cin >> n >> t;
	if(t == 10) {
		if(n == 1) {
			cout << -1;
			return 0;
		}
		cout << 1;
		addzero(n - 1);
	} else {
		cout << t;
		addzero(n - 1);
	}
}        
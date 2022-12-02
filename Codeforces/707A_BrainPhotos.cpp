#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, m;
	char c;
	cin >> n >> m;
	n *= m;
	for(int i = 0; i < n; ++i) {
		cin >> c;
		if(c == 'C' || c == 'M' || c == 'Y') {
			cout << "#Color";
			return 0;
		}
	}
	cout << "#Black&White";
	return 0;
}        
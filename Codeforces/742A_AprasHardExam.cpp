#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n;
	string ans = "8426";
	cin >> n;
	if(n == 0) {
		cout << 1;
	} else {
		--n;
		n %= 4;
		cout << ans[n];
	}

	return 0;
}        
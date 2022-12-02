#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int n, k, c = 0, l, r;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> l >> r;
		c += r - l + 1;
	}
	cout << (k - (c % k)) % k;
	return 0;
}
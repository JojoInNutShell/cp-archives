#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int n,k,a,b, af;
	cin >> n >> k;
	n = 2*n;
	cin >> af; cout << af;
	for(int i = 0; i < n; i += 2) {
		cin >> a >> b;
		if(k > 0 && af < a - 1 && a - 1 > b) {
			cout << " " << a - 1 << " " << b;
			--k;
		} else {
			cout << " " << a << " " << b;
		}
		af = b;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

multiset<int> a;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, t, c, prev = -1, high = -1;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> t;
		a.insert(t);
	}
	for(auto val : a) {
		if(prev == val) {
			++c;
		} else {
			c = 1;
		}
		prev = val;
		if(c > high) {
			high = c;
		}
	}
	if(n % 2 == 0) {
		if(high > n / 2) {
			cout << "NO";
		} else {
			cout << "YES";
		}
	} else {
		if(high > (n / 2) + 1) {
			cout << "NO";
		} else {
			cout << "YES";
		}
	}
	return 0;
}
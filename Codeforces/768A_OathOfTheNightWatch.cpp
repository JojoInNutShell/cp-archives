#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, t, mn, mx, c = 0;
	multiset<int> a;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> t;
		a.insert(t);
	}
	mn = *a.begin();
	mx = *prev(a.end());
	for(auto val : a) {
		if(val > mn && val < mx) {
			++c;
		}
	}
	cout << c;
}
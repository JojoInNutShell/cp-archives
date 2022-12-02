#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	vector<int> a;
	int n, t, taken, left, c;
	left = 0; a.reserve(107); taken = 0; c = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> t;
		left += t;
		a.push_back(t);
	}
	sort(a.begin(), a.begin() + n); //sort
	
	for(int i = n - 1; i >= 0 && taken <= left; --i) {
		taken += a[i];
		left -= a[i];
		++c;
	}
	cout << c;
}
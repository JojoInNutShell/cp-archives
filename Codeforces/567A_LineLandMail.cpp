#include <bits/stdc++.h>

using namespace std;

int main() {
	array<long, 100007> a;
	long n, t, mn, mx;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		//min
		if(i == 0) {
			mn = abs(a[i] - a[i + 1]);
		} else if(i == n - 1) {
			mn = abs(a[i] - a[i - 1]);
		} else {
			mn = min(abs(a[i] - a[i - 1]), abs(a[i] - a[i + 1]));
		}
		//max
		if(i == 0) {
			mx = abs(a[i] - a[n - 1]);
		} else if(i == n - 1) {
			mx = abs(a[i] - a[0]);
		} else {
			mx = max(abs(a[i] - a[n - 1]), abs(a[i] - a[0]));
		}
		cout << mn << " " << mx << endl;
	}
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	array<long long, 6> a, b;
	a.fill(0); b.fill(0);
	long long n, m, c;
	c = 0;
	cin >> n >> m;
	for(int i = 0; i < 5; ++i) {
		a[i] = n/5;
	}
	if(n % 5 != 0) {
		for(int i = 1; i <= n % 5; ++i) {
			a[i]++;
		}
	}
	
	for(int i = 0; i < 5; ++i) {
		b[i] = m/5;
	}
	if(m % 5 != 0) {
		for(int i = 1; i <= m % 5; ++i) {
			b[i]++;
		}
	}
	
	for(int i = 1; i < 5; ++i) {
		c += a[i] * b[5 - i];
	}
	c += a[0] * b[0];
	cout << c;
	
}
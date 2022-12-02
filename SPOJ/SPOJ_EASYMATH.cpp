#include <bits/stdc++.h>

using namespace std;

long long kpk(long long a, long long b) {
	return a*b / (__gcd(a, b));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	long long n, m, A, d, T, p1, p2;
	vector<long long> a;
	cin >> T;
	while(T--) {
		cin >> n >> m >> A >> d;
		p1 = 0;
		p2 = 0;
		a.clear(); a.push_back(A); a.push_back(A + d); a.push_back(A + (2*d)); a.push_back(A + (3*d)); a.push_back(A + (4*d));
		//Phase 1 (1..M)
		for(int i = 0; i < 5; ++i) {
			p1 += (m / a[i]);
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				p1 -= (m / kpk(a[i],a[j]));
			}
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				for(int k = j + 1; k < 5; ++k) {
					p1 += (m / kpk(a[i], kpk(a[j], a[k])));
				}
			}
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				for(int k = j + 1; k < 5; ++k) {
					for(int l = k + 1; l < 5; ++l) {
						p1 -= (m / kpk(a[i], kpk(a[j], kpk(a[k], a[l]))));
					}
				}
			}
		}
		p1 += (m / kpk(a[0], kpk(a[1], kpk(a[2], kpk(a[3], a[4])))));
		//Phase 2 (1..N - 1)
		n -= 1;
		for(int i = 0; i < 5; ++i) {
			p2 += (n / a[i]);
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				p2 -= (n / kpk(a[i],a[j]));
			}
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				for(int k = j + 1; k < 5; ++k) {
					p2 += (n / kpk(a[i], kpk(a[j], a[k])));
				}
			}
		}
		for(int i = 0; i < 5; ++i) {
			for(int j = i + 1; j < 5; ++j) {
				for(int k = j + 1; k < 5; ++k) {
					for(int l = k + 1; l < 5; ++l) {
						p2 -= (n / kpk(a[i], kpk(a[j], kpk(a[k], a[l]))));
					}
				}
			}
		}
		p2 += (n / kpk(a[0], kpk(a[1], kpk(a[2], kpk(a[3], a[4])))));
		cout << (m - n) - (p1 - p2) << endl;
	}
	return 0;
}
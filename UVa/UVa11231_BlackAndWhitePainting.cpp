#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, m, c, e;
	while(cin >> n >> m >> c) {
		if(n == 0 && m == 0 && c == 0) {
			return 0;
		}
		e = (n - 7) * (m - 7);
		if(e % 2 == 0) {
			cout << e / 2;
		} else {
			if(c == 0) {
				cout << e / 2;
			} else {
				cout << (e / 2) + 1;
			}
		}
		cout << endl;
	}
	return 0;
}
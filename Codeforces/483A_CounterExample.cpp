#include <bits/stdc++.h>

using namespace std;

int main() {
	long long l, r, range;
	cin >> l >> r;
	range = r - l + 1;
	if(range < 3 || (range < 4 && l % 2 != 0)) {
		cout << -1;
	} else {
		if(l % 2 == 0) {
			cout << l << " " << l + 1 << " " << l + 2;
		} else {
			cout << l + 1 << " " << l + 2 << " " << l + 3;
		}
	}
}
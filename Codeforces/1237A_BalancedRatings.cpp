#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, t;
	bool up = true;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> t;
		if(t % 2 != 0) {
			if(up) {
				t += 1;
				up = false;
			} else {
				t -= 1;
				up = true;
			}
		}
		cout << t / 2 << endl;
	}
	return 0;
}
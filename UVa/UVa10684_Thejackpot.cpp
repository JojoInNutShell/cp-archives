#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	long long n, t;
	while(cin >> n && n != 0) {
		long long c = 0, high = -1;
		for(int i = 0; i < n; ++i) {
			cin >> t;
			c += t;
			if(c < 0) {
				c = 0;
			}
			if(c > high) {
				high = c;
			}
		}
		if(high > 0) {
			cout << "The maximum winning streak is " << high << ".";
		} else {
			cout << "Losing streak.";
		} cout << endl;
	}
	return 0;
}
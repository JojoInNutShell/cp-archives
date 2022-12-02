#include <bits/stdc++.h>

using namespace std;

array<long long, 200007> arr;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	long long n, low, colision;
	string s;
	low = 100000000000;
	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'R') {
			if(i + 1 != n && s[i + 1] == 'L') {
				colision = (arr[i + 1] - arr[i]) / 2;
				if(colision < low) {
					low = colision;
				}
			}
		}
	}
	if(low == 100000000000) {
		cout << -1;
	} else {
		cout << low;
	}
	
	return 0;
}
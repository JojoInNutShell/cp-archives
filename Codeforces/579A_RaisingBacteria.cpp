#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	long long n,c = 0;
	cin >> n;
	while(n != 1) {
		if(n % 2 != 0) {
			++c;
		}
		n /= 2;
	}
	cout << c + 1;
	return 0;
}
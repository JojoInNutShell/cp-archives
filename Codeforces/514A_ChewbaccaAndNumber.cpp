#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int inv, notinv, h;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		notinv = s[i] - '0'; inv = 9 - notinv;
		h = min(notinv, inv);
		if(h == 0 && i == 0) {
			cout << 9;
		} else {
			cout << h;
		}
	}
	return 0;
}
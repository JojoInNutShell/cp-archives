#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, c, fr, fl, lr, ll;
	string s, stry = " ";
	c = 0; fr = 2000; fl = 2000; lr = -1; ll = -1;
	cin >> n;
	cin >> s;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'R') {
			if(i > lr) {
				lr = i;
			}
			if(i < fr) {
				fr = i;
			}
		} else if(s[i] == 'L') {
			if(i > ll) {
				ll = i;
			}
			if(i < fl) {
				fl = i;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if(stry[c] != s[i]) {
			stry += s[i];
			++c;
		} else {
			continue;
		}
	}
	stry.erase(0, 1); //Erase space
	if(stry == ".R.") {
		cout << fr + 1 << " " << lr + 2;
	} else if(stry == ".L.") {
		cout << ll + 1 << " " << fl;
	} else if(stry == ".RL.") {
		cout << fr + 1 << " " << fl;
	}
	return 0;
}
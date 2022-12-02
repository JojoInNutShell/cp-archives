#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int c;
	c = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); ++i) {
		c += (s[i] - '0');
	}
	if(c == 0) {
		cout << 0;
	} else if(c == 1) {
		cout << s.size() / 2;
	} else {
		cout << ((s.size() + 1) / 2);
	}
	return 0;
}
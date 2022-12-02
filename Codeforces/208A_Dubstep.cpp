#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	bool isWUB = false;
	string s;
	int c = 0;
	cin >> s;
	while(c <= s.size()) {
		if(s[c] == 'W') {
			++c;
			if(s[c] == 'U') {
				++c;
				if(s[c] == 'B') {
					s.erase(c - 2, 3);
					c -= 2;
					if(c != 0 && c != s.size() && !isWUB) {	
						s.insert(c, " ");
						isWUB = true;	
						++c;
					}
				} else {
					isWUB = false;
				}
			} else {
				isWUB = false;
			}
		} else {
			++c;
			isWUB = false;
		}
	}
	while(*(prev(s.end())) == ' ') {
		s.erase(prev(s.end()));
	}
	cout << s;
	
	return 0;
}        
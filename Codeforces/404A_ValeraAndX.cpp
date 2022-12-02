#include <bits/stdc++.h>
 
using namespace std;
 
set<char> diag, nondiag; 
vector<string> str;
 
int main() {
	int n, l, r;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		str.push_back(s);
	}
	l = 0; r = n - 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(j == l || j == r) {
				diag.insert(str[i][j]);
			} else {
				nondiag.insert(str[i][j]);
			}
		}
		++l; --r;
	}
	if(diag.size() == 1 && nondiag.size() == 1 && *(diag.begin()) != *(nondiag.begin())) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}        
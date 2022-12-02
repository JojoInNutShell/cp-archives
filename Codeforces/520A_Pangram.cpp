#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	set<char> ch;
	string s;
	int n;
	cin >> n;
	cin >> s;
	for(auto c : s) {
		ch.insert(::tolower(c));
	}
	if(ch.size() == 26) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
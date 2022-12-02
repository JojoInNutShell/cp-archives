#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	string s1, s2, s3;
	char ch;
	int sz1, sz2;
	getline(cin, s1, '|');
	getline(cin, s2, '\n');
	cin >> s3;
	
	while(!s3.empty()) {
		sz1 = s1.size();
		sz2 = s2.size();
		ch = s3.back();
		s3.pop_back();
		if(sz1 > sz2) {
			s2.push_back(ch);
		} else if (sz2 > sz1) {
			s1.push_back(ch);
		} else {
			s1.push_back(ch);
		}
	}
	if(s1.size() != s2.size()) {
		cout << "Impossible";
	} else {
		cout << s1 << "|" << s2;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

set<char> kgc; //KGoodChecker

void initkgc(int k) {
	kgc.clear();
	for(int i = 0; i <= k; ++i) {
		kgc.insert('0' + i);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	string s;
	int n, k, c;
	c = 0;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		initkgc(k);
		cin >> s;
		for(auto c : s) {
			kgc.erase(c);
		}
		if(kgc.size() == 0) {
			++c;
		}
	}
	cout << c;
}
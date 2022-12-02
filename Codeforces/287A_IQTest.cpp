#include <bits/stdc++.h>

using namespace std;

array<array<bool, 7>, 7> table;
set<pair<int, int>> dotloc;

bool checktable() {
	for(int i = 0; i <= 2; ++i) {
		for(int j = 0; j <= 2; ++j) {
			if(table[i][j] && table[i + 1][j] && table[i][j + 1] && table[i + 1][j + 1]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	//PHASE 1
	string s;
	dotloc.clear();
	for(int i = 0; i < 4; ++i) { //Input
		cin >> s;
		for(int j = 0; j < 4; ++j) {
			if(s[j] == '#') {
				table[i][j] = true;
			} else {
				dotloc.insert(make_pair(i, j));
				table[i][j] = false;
			}
		}
	}
	if(checktable()) { //NoRepaint
		cout << "YES";
		return 0;
	}
	for(auto p : dotloc) { //1 Paint
		table[p.first][p.second] = true;
		if(checktable()) {
			cout << "YES";
			return 0;
		}
		table[p.first][p.second] = false;
	}
	//PHASE 2
	dotloc.clear();
	for(int i = 0; i < 4; ++i) { //Invert
		for(int j = 0; j < 4; ++j) {
			if(table[i][j]) {
				table[i][j] = false;
				dotloc.insert(make_pair(i, j));
			} else {
				table[i][j] = true;
			}
		}
	}
	if(checktable()) { //NoRepaint
		cout << "YES";
		return 0;
	}
	for(auto p : dotloc) { //1 Paint
		table[p.first][p.second] = true;
		if(checktable()) {
			cout << "YES";
			return 0;
		}
		table[p.first][p.second] = false;
	}
	cout << "NO";
	return 0;
}
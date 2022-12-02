#include <bits/stdc++.h>
 
using namespace std;
 
map<string, int> a;
 
int main() {
	int n;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		auto it = a.find(s);
		if(it == a.end()) {
			a.insert(make_pair(s, 0));
		} else {
			(*it).second++;
		}
	}
	if(a.size() == 1) {
		cout << (*a.begin()).first;
	} else {
		pair<string, int> i, j;
		i = *(a.begin());
		j = *(next(a.begin()));
		if(i.second > j.second) {
			cout << i.first;		
		} else {
			cout << j.first;
		}
	}
}        
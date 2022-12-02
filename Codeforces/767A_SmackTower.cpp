#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int n, sz, t;
	set<int> a;
	cin >> n;
	sz = n;
	for(int i = 0; i < sz; ++i) {
		cin >> t;
		a.insert(t);
		while(!a.empty() && n == *(prev(a.end()))){
			cout << n << " ";
			a.erase(prev(a.end()));
			--n;
		}
		cout << endl;
	}
}
#include <bits/stdc++.h>

using namespace std;

set<int> cp; //CheckPair

int remainface(int a, int b) {
	cp.clear();
	for(int i = 1; i <= 6; ++i) {
		cp.insert(i);
	}
	cp.erase(a); cp.erase(7 - a); cp.erase(b); cp.erase(7 - b);
	return max(*(cp.begin()), *prev(cp.end()));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int n, f1, f2, a, b;
	cin >> n >> f1; f1 = max(f1, 7 - f1); //Highest face
	cin >> a >> b; //erase first side faces
	for(int i = 1; i < n; ++i) {
		cin >> a >> b;
		f2 = remainface(a, b);
		if (f1 != f2) {
			cout << "NO";
			return 0;
		}
		f1 = f2;
	}
	cout << "YES";
}
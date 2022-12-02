#include <bits/stdc++.h>
 
using namespace std;
 
set<int> plist({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59});
 
int main() {
	int n, m;
	cin >> n >> m;
	auto it = plist.find(n);
	if(*(next(it)) == m) {
		cout << "YES";
	} else {
		cout << "NO";
	}
	
	return 0;
}        
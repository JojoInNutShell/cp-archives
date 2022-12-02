#include <bits/stdc++.h>

using namespace std;

bool different(int a, int b, int c, int d) {
	set<int> arr;
	arr.insert(a); arr.insert(b); arr.insert(c); arr.insert(d);
	if(arr.size() == 4) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int r1,r2,c1,c2,d1,d2,p11,p12,p21,p22;
	cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
	for(int i = 1; i < r1; ++i) {
		if(i > 9 || r1 - i > 9) {
			continue;
		}
		for(int j = 1; j < r2; ++j) {
			if(j > 9 || r2 - j > 9) {
				continue;
			}
			p11 = i; p12 = r1 - i; p21 = j; p22 = r2 - j;
			if(p11 + p21 == c1 && p12 + p22 == c2 && p11 + p22 == d1 && p12 + p21 == d2 && different(p11,p12,p21,p22)) {
				cout << p11 << " " << p12 << endl;
				cout << p21 << " " << p22 << endl;
				return 0;
			}
		}
	}
	cout << -1;
	return 0;
}
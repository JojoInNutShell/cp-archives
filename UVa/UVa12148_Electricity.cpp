#include <bits/stdc++.h>

using namespace std;

array<int, 4> dmyc1, dmyc2;
array<int, 3> res;
array<int, 12> day = {31,28,31,30,31,30,31,31,30,31,30,31};

void printres() {
	for(auto val : res) {
		cout << val << " ";
	}
	cout << endl;
}

bool lpyear(int n) {
	if(n % 400 == 0) {
		return true;
	}
	if(n % 4 == 0) {
		if(n % 100 != 0) {
			return true;
		}
	}
	return false;
}

void nextday(int d, int m, int y) {
	if(d < day[m - 1]) {
		res[0] = d + 1; res[1] = m; res[2] = y;
		return;
	} else {
		if(m == 2) {
			if(d == 28 && lpyear(y)) {
				res[0] = d + 1; res[1] = m; res[2] = y;
				return;
			} else {
				res[0] = 1; res[1] = m + 1; res[2] = y;
				return;
			}
		} else if (m == 12) {
			res[0] = 1; res[1] = 1; res[2] = y + 1;
			return;
		} else {
			res[0] = 1; res[1] = m + 1; res[2] = y;
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	
	int n, d1, m1, y1, c1, d2, m2, y2, c2, daycount, capcount;
	while(cin >> n) {
		daycount = 0; capcount = 0;
		if(n == 0) {
			return 0;
		}
		cin >> d1 >> m1 >> y1 >> c1;
		nextday(d1, m1, y1);
		for(int i = 1; i < n; ++i) {
			cin >> d2 >> m2 >> y2 >> c2;
			if(res[0] == d2 && res[1] == m2 && res[2] == y2) {
				capcount += c2 - c1;
				daycount += 1;
			}
			d1 = d2; m1 = m2; y1 = y2; c1 = c2;
			nextday(d2, m2, y2);
		}
		cout << daycount << " " << capcount << endl;
	}
	return 0;
}
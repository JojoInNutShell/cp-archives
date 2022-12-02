#include <bits/stdc++.h>

using namespace std;

int c;
array<array<pair<bool, int>, 30>, 30> arr; //pair = {eagle?, group}

void printarr(int n) {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			cout << arr[i][j].first;
		}
		cout << endl;
	}
}

void printars(int n) {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= n; ++j) {
			cout << arr[i][j].second;
		}
		cout << endl;
	}
}

bool dfs(int i, int j, int c) {
	if(arr[i][j].second != - 1) {
		return false;
	} else {
		arr[i][j].second = c;
		for(int k = i - 1; k <= i + 1; ++k) {
			for(int l = j - 1; l <= j + 1; ++l) {
				if(i == k && j == l) {
					continue;
				}
				if(arr[k][l].first) {
					dfs(k, l, c);
				}
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, curimg = 1;
	string s;
	while(cin >> n) {
		c = 0; //No Group
		++n; //Size is n + 2;
		for(int i = 0; i <= n; ++i) {
			if(i == 0 || i == n) {
				for(int j = 0; j <= n; ++j) {
					arr[i][j] = make_pair(0, -1); //No Eagle no grup
				}
			} else {
				cin >> s;
				for(int j = 0; j <= n; ++j) {
					if(j == 0 || j == n) {
						arr[i][j] = make_pair(0, -1);
					} else {
						arr[i][j] = make_pair(s[j - 1] - '0', -1); 
					}
				}
			}
		}
		c = 0;
		for(int i = 1; i < n; ++i) {
			for(int j = 1; j < n; ++j) {
				if(arr[i][j].first) {
					if(dfs(i, j, c + 1)) {
						++c;
					}
				}
			}
		}
		cout << "Image number " << curimg << " contains " << c << " war eagles." << endl;
		++curimg;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

//DATA STRUCTURES SHORTCUT
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, m, c, T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		cout << (n - 1) + ((n + n - 1) * (m - 1)) << endl;
	}
	
	return 0;
}
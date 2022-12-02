#include<bits/stdc++.h>
using namespace std;

//#define int long long
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int FMOD = 998244353; 
const ll INF = 1e9;
const ld EPS = 1e-9;
const double PI=acos(-1);

#define fi first
#define se second

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................
bool visitt[106][106];
int a[106];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	memset(visitt, 0, sizeof(visitt));
	int sz;
	for(int i = 0; i < m; ++i) {
		cin >> sz;
		for(int j = 0; j < sz; ++j) cin >> a[j];
		for(int j = 0; j < sz; ++j) {
			for(int k = j + 1; k < sz; ++k) {
				//cerr << a[j] << " " << a[k] << endl;
				visitt[a[j]][a[k]] = true;
			}
		}
	}
	bool ok = true;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			if(!visitt[i][j]) ok = false;
		}
	}
	if(ok) cout << "Yes";
	else cout << "No";
	return 0;
}
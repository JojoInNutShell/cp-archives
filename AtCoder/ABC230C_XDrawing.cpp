#include<iostream>
#include<cmath>
using namespace std;

#define int long long
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, a, b;
	int p, q, r, s;
	cin >> n >> a >> b;
	int sel = a - b, ad = a + b;
	cin >> p >> q >> r >> s;
	int k1min = max(1 - a, 1 - b), k1max = min(n - a, n - b);
	//cerr << k1min << " " << k1max << endl;
	int k2min = max(1 - a, b - n), k2max = min(n - a, b - 1);
	//cerr << k2min << " " << k2max << endl;
	for(int x = p; x <= q; ++x) {
		for(int y = r; y <= s; ++y) {
			if(a + k1min <= x && x <= a + k1max && b + k1min <= y && y <= b + k1max && x - y == sel) {
				cout << '#';
			} else if(a + k2min <= x && x <= a + k2max && b - k2min >= y && y >= b - k2max && x + y == ad) {
				cout << '#';
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
	
	return 0;
}
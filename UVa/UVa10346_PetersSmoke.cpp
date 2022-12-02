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
	int n, k;
	while(cin >> n >> k) {
		int waste = 0, sum = 0;
		while(n != 0) {
			sum += n;
			waste += n;
			n = waste/k;
			waste %= k;
		}
		cout << sum << endl;
	}
	return 0;
}
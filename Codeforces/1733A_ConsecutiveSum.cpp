#include<iostream>
#include<cmath>
#include<vector>
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
	int T;
	cin >> T;
	int n, k;
	while(T--) {
		cin >> n >> k;
		vector<int> arr(n), par;
		//for(int i = 0; i < n; ++i) {}
		par.assign(n, 0);
		for(int i = 1; i <= n; ++i) {
			cin >> arr[i - 1];
			par[i % k] = max(par[i % k], arr[i - 1]);
		}
		ll sum = 0;
		for(int i = 0; i < k; ++i) {
			sum += par[i];
		}
		cout << sum << endl;
	}
	return 0;
}
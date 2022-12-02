#include<bits/stdc++.h>
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
ll dp[1000007];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> coin(n);
	for(int i = 0; i < n; ++i) cin >> coin[i];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i <= x; ++i) {
		for(auto c : coin) {
			if(i + c <= x) dp[i + c] += dp[i], dp[i + c] %= MOD;
		}
		dp[i] %= MOD;
	}
	cout << dp[x];
	return 0;
}
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
int memo[1000007];

int dp(int m) {
	//cerr << m << endl;
	if(memo[m] != -1) return memo[m];
	if(m == 0) return memo[m] = 0;
	else {
		string s = to_string(m);
		int ans = INF;
		for(auto c : s) {
			if(c == '0') continue;
			ans = min(ans, dp(m - (c - '0')) + 1);
		}
		return memo[m] = ans;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	memset(memo, -1, sizeof(memo));
	cout << dp(n);
	return 0;
}
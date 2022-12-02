#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define LSB(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

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
typedef pair<int, int> ii;  
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int,int> mii; 

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................
ll dp[1000007][2];

/*
ll fexp(int e) {
	if(e == 0) return 1;
	ll half = fexp(e/2);
	if(e % 2 == 1) return (2*half*half) % MOD;
	else return half*half % MOD;
}

ll dp(int n) {
	if(memo[n] != -1) return memo[n];
	else if(n == 1) return memo[n] = 0;
	else {
		ll res = n;
		for(int i = 1; i <= n; ++i) {
			res += dp(n - i) + fexp(2*(i - 1));
			res %= MOD;
		}
		return memo[n] = res % MOD;
	}
}
*/

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T, n;
	//memset(memo, -1, sizeof(memo));
	dp[1][0] = dp[1][1] = 1;
	cin >> T;
	int calc = 1;
	while(T--) {
		cin >> n;
		for(int i = calc; i < n; ++i) {
			dp[i + 1][0] = (2*dp[i][0] + dp[i][1]) % MOD;
			dp[i + 1][1] = (4*dp[i][1] + dp[i][0]) % MOD;
		}
		calc = max(calc, n);
		cout << (dp[n][0] + dp[n][1]) % MOD << endl;
	}
	return 0;
}
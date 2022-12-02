#include <bits/stdc++.h>
using namespace std;

#define int long long
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
ll memo[100006][106];
int arr[100002];
int n, m;

ll dp(int i, int b) {
	if(memo[i][b] != -1) return memo[i][b];
	if(i >= n) return memo[i][b] = 1;
	else if(i == 0) {
		int res = 0;
		if(arr[i] == 0) {
			for(int k = 1; k <= m; ++k) res += dp(i + 1, k);
		} else {
			res += dp(i + 1, arr[i]);
		}
		return memo[i][b] = res % MOD;
	} else {
		int res = 0;
		if(arr[i] == 0) {
			for(int k = max(b - 1, 1LL); k <= min(b + 1, m); ++k) {
				res += dp(i + 1, k);
			}
		} else {
			if(abs(b - arr[i]) > 1) return memo[i][b] = 0;
			res += dp(i + 1, arr[i]);
		}
		return memo[i][b] = res % MOD;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	memset(memo, -1, sizeof(memo));
	ll ans = dp(0, 0);
	cout << ans;
	return 0;
}
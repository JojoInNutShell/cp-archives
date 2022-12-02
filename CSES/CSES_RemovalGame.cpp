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
int n;
ll memo[5006][5006][2];
int arr[5006];

ll dp(int l, int r, int p) {
	if(memo[l][r][p] != 0) return memo[l][r][p];
	if(p == 0) {
		if(l == r) {
			return memo[l][r][p] = arr[l]; 
		} else {
			return memo[l][r][p] = max(dp(l + 1, r, p^1) + arr[l], dp(l, r - 1, p^1) + arr[r]);
		}
	} else {
		if(l == r) {
			return memo[l][r][p] = -arr[l];
		} else {
			return memo[l][r][p] = min(dp(l + 1, r, p^1) - arr[l], dp(l, r - 1, p^1) - arr[r]);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; ++i) cin >> arr[i], sum += arr[i];
	memset(memo, 0, sizeof(memo));
	ll ans = dp(0, n - 1, 0);
	ans = (ans + sum + (ans + sum < 0 ? -1 : 1))/2;
	cout << ans;
	return 0;
}
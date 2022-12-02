/*
	Author: MikiMiku
	
	Observation:
		1. Solution doesn't exist when
		a string can't be lexicographically
		smaller for any possible string before
		it (which is only the normal and the reversed)
		
	Idea: 
		Naively, we could just try every possible
		0 - 1 subset (normal or reversed) and check
		its validity and optimality. But, let's
		imagine our final solution as set of all
		string chosen. The n-th string have two possible
		solution which is the normal or the reversed ones.
		But we could see that the n-th string must
		follow the must be larger than or equal to
		(lexicographically) the n -1 th string, which
		could be either normal or reversed one.
		So, we may solve this task by DP.
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
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
const ll INF = 1e16;
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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................
ll dp[2][100007];
array<array<string, 100007>, 2> s;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	
	vector<ll> c(n);
	for(int i = 0; i < n; ++i) cin >> c[i];
	
	for(int i = 0; i < n; ++i) {
		cin >> s[0][i];
		
		s[1][i] = s[0][i];
		reverse(all(s[1][i]));
	}
	
	reverse(all(c));
	reverse(s[0].begin(), s[0].begin() + n);
	reverse(s[1].begin(), s[1].begin() + n);
	
	for(int i = 0; i < 2; ++i) {
		for(int j = 0; j < n; ++j) dp[i][j] = INF;
	}
	
	dp[0][0] = 0;
	dp[1][0] = c[0];
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < 2; ++j) {
			if(j == 0) {
				if(s[0][i - 1] >= s[j][i]) {
					dp[j][i] = min(dp[j][i], dp[0][i - 1]);
				}
				if(s[1][i - 1] >= s[j][i]) {
					dp[j][i] = min(dp[j][i], dp[1][i - 1]);
				}
			} else {
				if(s[0][i - 1] >= s[j][i]) {
					dp[j][i] = min(dp[j][i], dp[0][i - 1] + c[i]);
				}
				if(s[1][i - 1] >= s[j][i]) {
					dp[j][i] = min(dp[j][i], dp[1][i - 1] + c[i]);
				}
			}
		}
	}
	
	ll ans = min(dp[0][n - 1], dp[1][n - 1]);
	if(ans == INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
int c[3006], s[3006];
int dp[4][3006];
int n;

int f() {
	for(int i = 0; i < n; ++i) {
		dp[1][i] = c[i];
	}
	for(int i = 2; i <= 3; ++i) {
		for(int j = 0; j < n; ++j) {
			dp[i][j] = INF;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < i; ++j) {
			if(s[j] < s[i]) {
				dp[2][i] = min(dp[2][i], dp[1][j] + c[i]);
				dp[3][i] = min(dp[3][i], dp[2][j] + c[i]);
			}
		}
	}
	/*
	for(int i = 1; i <= 3; ++i) {
		for(int j = 0; j < n; ++j) {
			cerr << dp[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	int mn = INF;
	for(int i = 0; i < n; ++i) {
		mn = min(mn, dp[3][i]);
	}
	if(mn == INF) {
		return -1;
	} else {
		return mn;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> s[i];
	for(int i = 0; i < n; ++i) cin >> c[i];
	cout << f();
	
	return 0;
}
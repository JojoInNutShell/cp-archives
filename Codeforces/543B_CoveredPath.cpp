#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int v1, v2;
int d;
int memo[4000][2000];

int dp(int v, int t) {
	if(memo[v + 2000][t] != -1) return memo[v + 2000][t];
	if(t == 1) {
		if(v != v2) return memo[v + 2000][t] = -INF;
		else return memo[v + 2000][t] = v2;
	} else if(v < 0) {
		return memo[v + 2000][t] = -INF;
	} else {
		int mx = -INF;
		for(int i = -d; i <= d; ++i) {
			mx = max(mx, dp(v + i, t - 1) + v);
		}
		//cerr << v << " " << t << " " << mx << endl;
		return memo[v + 2000][t] = mx;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> v1 >> v2;
	cin >> t >> d;
	memset(memo, - 1, sizeof(memo));
	cout << dp(v1, t); 
	
	return 0;
}
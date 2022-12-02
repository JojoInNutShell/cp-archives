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
//........................................................................
int memo[2006][1006];
int p[1006], key[2006];
int n, k, m;

int dp(int nk, int idx) {
	for(int i = 0; i <= nk; ++i) {
		for(int j = 0; j <= idx; ++j) {
			memo[i][j] = INF;
		}
	}
	memo[0][0] = 0;
	int dist;
	for(int i = 0; i < nk; ++i) {
		for(int j = 0; j <= idx; ++j) {
			memo[i + 1][j] = min(memo[i + 1][j], memo[i][j]);
			
			dist = abs(p[j] - key[i]) + abs(key[i] - m);
			if(j < idx) {
				memo[i + 1][j + 1] = min(memo[i + 1][j + 1], max(memo[i][j], dist));
			}
		}
	}
	return memo[nk][idx];
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> k >> m;
	for(int i = 0; i < n; ++i) cin >> p[i];
	for(int i = 0; i < k; ++i) cin >> key[i];
	sort(p, p + n);
	sort(key, key + k);
	cout << dp(k, n);
	
	return 0;
}
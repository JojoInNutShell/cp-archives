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
int memo[506][506];

int dp(int p, int l) {
	if(memo[p][l] != -1) return memo[p][l];
	else if(p == l) return memo[p][l] = 0;
	else if(p == 1) return memo[p][l] = l - 1;
	else if(l == 1) return memo[p][l] = p - 1;
	else {
		int mn = INF;
		for(int i = 1; i <= p/2; ++i) {
			mn = min(mn, dp(i, l) + dp(p - i, l) + 1);
		}
		for(int i = 1; i <= l/2; ++i) {
			mn = min(mn, dp(p, i) + dp(p, l - i) + 1);
		}
		return memo[p][l] = mn;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int a, b;
	cin >> a >> b;
	memset(memo, -1, sizeof(memo));
	cout << dp(a, b);
	/*
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			cerr << memo[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	return 0;
}
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
string s1, s2;
int memo[5006][5006];

int dp(int sz1, int sz2) {
	if(memo[sz1][sz2] != -1) return memo[sz1][sz2];
	else if(sz1 == 0) return memo[sz1][sz2] = sz2;
	else if(sz2 == 0) return memo[sz1][sz2] = sz1;
	else {
		if(s1[sz1 - 1] == s2[sz2 - 1]) {
			return memo[sz1][sz2] = dp(sz1 - 1, sz2 - 1);	
		} else {
			return memo[sz1][sz2] = min(dp(sz1 - 1, sz2), min(dp(sz1, sz2 - 1), dp(sz1 - 1, sz2 - 1))) + 1;
		}
	} 
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> s1 >> s2;
	memset(memo, -1, sizeof(memo));
	cout << dp(sza(s1), sza(s2));
	/*
	for(int i = 0; i <= sza(s1); ++i) {
		for(int j = 0; j <= sza(s2); ++j) {
			cerr << memo[i][j] << " ";
		}
		cerr << endl;
	}
	*/
	return 0;
}
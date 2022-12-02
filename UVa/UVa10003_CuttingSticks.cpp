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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................
int r, n;
int a[57];
bitset<1007> bs;
ll memo[1007][1007];

ll dp(int i, int j) {
	//cerr << i << " " << j << endl;
	if(memo[i][j] != -1) return memo[i][j];
	
	ll res = INF;
	ll cost = j - i;
	ll c = 0;
	for(int k = i + 1; k < j; ++k) {
		if(bs[k]) {
			c++;
			res = min(res, dp(i, k) + dp(k, j) + cost);
		}
	}
	if(c == 0) res = 0;
	//cerr << i << " " << j << " " << res << endl;
	return memo[i][j] = res;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	while(cin >> r) {
		if(r == 0) break;
		int n;
		cin >> n;
		
		bs.reset();
		for(int i = 0; i < n; ++i) cin >> a[i], bs[a[i]] = true;
		
		memset(memo, -1, sizeof(memo));
		
		ll ans = dp(0, r);
		
		cout << "The minimum cutting is " << ans << "." << endl;
	}
	return 0;
}
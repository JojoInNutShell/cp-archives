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
vector<ll> primes;
bitset<1000007> bs;

void sieve(ll n) {
	bs.set();
	bs[0] = bs[1] = false;
	for(ll i = 1; i <= n; ++i) {
		if(bs[i]) {
			for(ll j = i*i; j <= n; j += i) bs[j] = false;
			primes.pb(i);
		}
	}
}

ll tab[507][507];
ll tabc[507][507];

ll col[507], row[507];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(1000004);
	
	int n, m;
	cin >> n >> m;
	
	memset(tabc, 0, sizeof(tabc));
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> tab[i][j];
			
			auto it = lower_bound(all(primes), tab[i][j]);
			ll idx = it - primes.begin();
			ll rval = INF;
			rval = primes[idx];
			
			tabc[i][j] = rval - tab[i][j];
			//cerr << tabc[i][j] << " ";
			
			row[i] += tabc[i][j];
			col[j] += tabc[i][j];
		} //cerr << endl;
	}
	
	ll ans = INF;
	for(int i = 0; i < n; ++i) {
		ans = min(ans, row[i]);
	}
	for(int i = 0; i < m; ++i) {
		ans = min(ans, col[i]);
	}
	
	cout << ans << endl;
	return 0;
}
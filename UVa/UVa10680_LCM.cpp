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
vector<int> primes;
unordered_map<int, int> curKPK;
bitset<1100006> bs;
ll SieveSize;

void sieve(int u) {
	SieveSize = u + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i <= SieveSize; ++i) {
		//cerr << i << endl;
		if(bs[i]) {
			for(int j = 2*i; j <= SieveSize; j += i) {
				//cerr << j << endl;
				bs[j] = false;
			}
			primes.pb(i);
		}
	}
}

int fastexp(int n, int e) {
	if(e == 0) return 1;
	int half = fastexp(n, e/2);
	if(e%2 == 0) {
		return half*half;
	} else {
		return n*half*half;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(1100000);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		vector<ii> ans;
		int res = 1;
		int idx = 0, PF = primes[idx], c5 = 0;
		while(PF <= n) {
			int c = 1;
			for(; n/fastexp(PF, c) > 0; ++c);
			if(PF == 5) c5 = c - 1;
			else ans.pb({PF, c - 1});
			PF = primes[++idx];
		}
		for(auto& p : ans) {
			if(p.fi == 2) p.se -= c5;
			res *= fastexp(p.fi, p.se);
			res %= 10;
		}
		cout << res % 10 << endl;
	}
	return 0;
}
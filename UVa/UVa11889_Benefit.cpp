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
bitset<5006> bs;
ll SieveSize;

void sieve(int u) {
	SieveSize = u + 1;
	bs.set();
	bs[0] = bs[1] = false;
	for(int i = 2; i <= SieveSize; ++i) {
		if(bs[i]) {
			for(int j = i*i; j <= SieveSize; j += i) {
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
	sieve(5000);
	int T;
	cin >> T;
	int a, c;
	while(T--) {
		cin >> a >> c;
		map<int, int> PFListA, PFListC;
		int idx = 0, PF = primes[idx];
		while(PF*PF <= a) {
			while(a % PF == 0) a /= PF, PFListA[PF]++;
			PF = primes[++idx];
		}
		if(a != 1) PFListA[a]++;
		idx = 0; PF = primes[idx];
		while(PF*PF <= c) {
			while(c % PF == 0) c /= PF, PFListC[PF]++;
			PF = primes[++idx];
		}
		if(c != 1) PFListC[c]++; 
		bool noans = false;
		for(auto p : PFListA) {
			if(p.se > PFListC[p.fi]) {
				noans = true;
				break;
			} else if(p.se == PFListC[p.fi]) {
				PFListC.erase(p.fi);
			}
		}
		int res = 1;
		if(noans) cout << "NO SOLUTION" << endl;
		else {
			for(auto p : PFListC) {
				res *= fastexp(p.fi, p.se);
			}
			cout << res << endl;
		}
 	}
	return 0;
}
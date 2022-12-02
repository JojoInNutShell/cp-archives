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
ii PFmx[20000006];
bitset<20000006> bs;
ll SieveSize;

void sieve(int b) {
	SieveSize = b + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	memset(PFmx, 0, sizeof(PFmx));
	PFmx[0].fi = PFmx[0].se = -1; PFmx[1].fi = PFmx[1].se = -1;
	for(int i = 2; i <= SieveSize; ++i) {
		if(bs[i]) {
			for(int j = 2*i; j <= SieveSize; j += i) {
				bs[j] = false;
				if(PFmx[j].fi == 0) {
					PFmx[j].fi = i;
					PFmx[j].se = i;
				}
				else {
					PFmx[j].se = i;
				}
			}
			primes.pb(i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(20000000);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		n = abs(n);
		if(n < 20000000) {
			if(bs[n]) {
				cout << -1 << endl;
				continue;
			} else {
				if(PFmx[n].fi == PFmx[n].se) {
					cout << -1 << endl;
				} else {
					cout << PFmx[n].se << endl;
				}
				continue;
			}
		} else {
			int idx = 0, PF = primes[idx], mx = 1, mn = 1e15;
			int tmpn = n;
			while(PF*PF <= n) {
				while(n % PF == 0) n /= PF, mx = PF, mn = min(mn, PF);
				PF = primes[++idx];
			}
			if(n != 1) mx = max(n, mx);
			if(tmpn == n || mn == mx) {
				cout << -1 << endl;
				continue;
			}
			cout << mx << endl;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
const ll MOD = 1073741824;
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
ll memo[1000006];
bitset<1006> bs;
vector<int> primes;

void sieve(int n) {
	bs.set();
	bs[0] = bs[1] = false;
	for(int i = 2; i <= n; ++i) {
		if(bs[i]) {
			for(int j = i*i; j <= n; j += i) {bs[j] = false;}
			primes.pb(i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(1003);
	//cerr << sza(primes) << endl;
	int a, b, c;
	cin >> a >> b >> c;
	memset(memo, 0, sizeof(memo));
	ll ans = 0;
	for(int i = 1; i <= a; ++i) {
		for(int j = 1; j <= b; ++j) {
			for(int k = 1; k <= c; ++k) {
				ll num = i*j*k;
				//cerr << num << endl;
				if(memo[num] != 0) {
					ans += memo[num];
					ans %= MOD;
				} else {
					ll div = 1;
					int tmp = num;
					int PF_idx = 0, PF = primes[PF_idx];
					while(PF*PF <= tmp) {
						int c = 1;
						while(tmp % PF == 0) {
							c++; tmp /= PF;
						}
						div *= c;
						PF = primes[++PF_idx];
					}
					if(tmp != 1) div*=2;
					memo[num] = div;
					ans += memo[num];
					ans %= MOD;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
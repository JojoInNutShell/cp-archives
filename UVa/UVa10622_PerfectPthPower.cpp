/*
	Author: MikiMiku
	 
	Idea: 
		Say a number N,
		It can be represented as prime factorization
		as follows,
		
		N = (p1^e1) * (p2^e2) * ... * (pn^en)
		
		or
		
		N = ((p1^e1) * (p2^e2) * ... * (pn^en))^1
		
		It means that currently N is in
		perfect 1-th power. But by the prime
		factorization representation we may
		get better p-th power (if exists).
		Hence the answer for N >= 0 is just
		the gcd of e1,e2,...,en as we can later
		factor out the exponent by the result of the gcd.
		Increasing the perfect power to the result.
		
		But special case here where N < 0 or N is negative number.
		We know that (-1)^(k) = (-1) where k is an odd integer.
		Hence, for the negative one our perfect p-th power
		is just limited to odd integer. So, after obtaining
		the prime factorization of N we could just try
		one by one every possible answer which is k.
		Where k is odd integer ranging from 1 to 31. As 31
		is the highest possible answer where N is 2^31 or -2^31.
		
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
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
vector<int> primes;
bitset<1000007> bs;

void sieve(ll n) {
	bs.set();
	bs[0] = bs[1] = false;
	for(ll i = 2; i <= n; ++i) {
		if(bs[i]) {
			for(ll j = i*i; j <= n; j += i) bs[j] = false;
			primes.eb(i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(1 << 16);
	ll x;
	while(cin >> x) {
		if(x == 0) break;
		
		bool neg = false;
		if(x < 0) {
			x = abs(x);
			neg = true;
		}
		
		ll pid = 0, p = primes[pid];
		vector<int> pfc;
		while(p*p <= x) {
			ll c = 0;
			while(x % p == 0) {
				x /= p;
				c++;
			}
			if(c != 0) {
				pfc.pb(c);
			} 
			p = primes[++pid];
		} 
		if(x > 1) pfc.pb(1);
		
		int ans = 1;
		if(neg) {
			for(int i = 1; i <= 31; i+=2) {
				bool ok = true;
				for(int j = 0; j < sza(pfc); ++j) {
					if(pfc[j] % i != 0) {
						ok = false;
						break;
					}
				}
				if(ok) ans = i;
			}
		} else {
			ans = pfc[0];
			for(int i = 1; i < sza(pfc); ++i) ans = __gcd(ans, pfc[i]);
		}
		
		cout << ans << endl;
	}
	return 0;
}
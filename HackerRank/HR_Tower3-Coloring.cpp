/*
	Author: MikiMiku
	
	Observation:
		The answer seem to be obvious, we
		have 3^n blocks, and 3 colors. Hence,
		the amount of different colorings that
		could be made is 3^(3^n) (MOD 1e9 + 7).
		
		But notice that when n is also 1e9. The
		answer went way too large even for binary
		exponentiation who have O(lg e) (e for
		the exponent) complexity. log2(3^1e9) is
		1e9*log2(3). (Which is too many operations)
		
		We need help from number theory. Notice that
		the number which we mod to is prime.
		Hence, here we may apply fermat little
		theorem which is,
		
		a^(p - 1) === 1 (mod p) (where p is prime)
		
		So,
		
		3^( 3^n (mod 1e9 + 6) ) (mod 1e9 + 7)
		
		is a valid thing to do, this will improve
		the calculation need from,
		
		log2(3^1e9)
		
		to
		
		log2(3^log2(1e9))
		
		which is a small number.
		
	Idea: 
		Just implement the binary exponentiation and
		the formula on the observation.
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

ll fexpm(ll b, ll e, ll m) {
	b %= m;
	ll ans = 1;
	while(e > 0) {
		if(e%2 == 1) {
			ans *= b;
		}
		
		b *= b;
		
		b %= m;
		ans %= m;
		
		e >>= 1;
	}
	
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll n;
	cin >> n;
	
	ll ans = fexpm(3, fexpm(3, n, MOD - 1), MOD);
	cout << ans << endl;
	return 0;
}
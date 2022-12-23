/*
	Author: MikiMiku
	
	Observation:
		1. If the current number is prime, then
		no move can be make.
		
		This follows immediately from the
		definition of prime which divisors are
		only 1 and the number itself which is all
		trivial divisors.
		
		2. If the current number is in form
		of p1*p2 where p1 and p2 are prime numbers.
		Then the current legal move available
		will always lead to observation 1.
		
		The current player may only choose
		p1 or p2 as it's move, hence making
		the next number must be prime. (Which
		will put players into observation 1 situation)
		
		3. If the current number is in form
		p1*p2*p3*...*pn with n > 2 (Also it's
		fine for p1 == p2 or p2 == p4 or whatever).
		Then the current best move is to take
		p1*p2 (or generally any pair of prime number)
		which will leads us to observation 2 situation
		where the opposite player must be losing.
		
	Idea:
		Looking the number in it's prime
		factorization form will make clear
		of every legal moves available. 
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
bitset<5000000> bs;
vector<ll> primes;

void sieve(ll n) {
	bs.set();
	bs[0] = bs[1] = false;
	for(ll i = 2; i <= n; ++i) {
		if(bs[i]) {
			for(ll j = i*i; j <= n; j += i) bs[j] = false;
			primes.pb(i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(4000000);
	
	ll q;
	cin >> q;
	
	vector<ll> pl;
	ll idp = 0, pr = primes[idp];
	while(pr*pr <= q) {
		while(q%pr == 0) pl.pb(pr), q/=pr;
		pr = primes[++idp];
	}
	if(q != 1) pl.pb(q);
	
	if(sza(pl) > 2) {
		ll ans = pl[0]*pl[1];
		cout << "1" << endl;
		cout << ans << endl;
	} else if(sza(pl) == 2) {
		cout << "2" << endl;
	} else {
		cout << "1" << endl;
		cout << "0" << endl;
	}
	return 0;
}
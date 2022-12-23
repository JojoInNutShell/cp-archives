/*
	Author: MikiMiku
	
	Observation:
		Given two numbers from the task. Let's
		say they are n and m (n > m). Observe that the 
		transition of that pair of number will be,
		
		(Example 1)
		
		n m (n > m)
		n%m m (p = n%m, then m > p)
		p m%p (q = m%p, then p > q)
		p%q q (r = p%q, then q > r)
		... (and so on until one of them equals to 0)
		
		But notice that before n m pair become p m (p = n%m) pair.
		There may be some options of substracting.
		
		(Example 2)
		
		 n        m (At first) (n > m)
		(n - m)   m
		(n - 2*m) m
		(n - 3*m) m
		...
		(n - q*m) m (Where q is the quotient of n/m) (Also note that n - q*m == n%m)
		
		Stan, Ollie, or whoever moves at that
		current game state may change the pair n m
		to any (n - c*m) m (where 1 <= c <= q).
		
		After some moves n m pair will become
		p m (where p = n%m) and the game keeps
		going on with the same fact. If we
		list all the quotient of every transition
		
		(Refer to example 1)
		
		List:
		q1 (from n/m)
		q2 (from m/p)
		q3 (from p/q)
		...
		qn
		
		Then if we do some moves on the game, it
		will substract q1 first with number c, where
		c must be a natural number less than q1 (1 <= c <= q1).
		q1 will always get substracted until it reach
		zero. Then we move to q2, then q3 and the
		person to make qn == 0 is the winner.
		
		Notice that it's somewhat similar to nim game.
		Hence from here we can translate the game
		into nim game.
		
	Idea: 
		We can do it manually calculate every
		state of the game, but this will lead
		us to TLE. Little observation needed to 
		determine the winner faster.
		Just calculate manually and see the pattern
		for any q1, q2, q3, ..., qn.
		
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll n, m;
	while(cin >> n >> m) { 
		if(n == 0 && m == 0) break;
		if(n < m) swap(n, m);
		
		vector<ll> nim;
		while(m != 0) {
			nim.pb(n/m);
			n%=m;
			swap(n, m);
		}
		
		bool st = 1; nim.pop_back();
		while(!nim.empty()) {
			if(nim.back() > 1) st = 1;
			else st ^= 1;
			nim.pop_back();
		}
		
		if(st) {
			cout << "Stan wins" << endl;
		} else {
			cout << "Ollie wins" << endl;
		}
	}
	
	
	return 0;
}
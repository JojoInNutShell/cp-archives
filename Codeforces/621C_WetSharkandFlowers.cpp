/*
	Author: MikiMiku
	
	Definition:
		1. a | b (a divides b)
		2. axb or a.b (a times b)
	
	Observation:
		1. If p | Si.Sj then p | Si or p | Sj.
		
		It follows from the fact that prime just
		could be made up by the prime itself
		(As prime is only divisible by 1 and
		by itself). So p may be in Si or Sj or both.
		Hence, at least one of the p | Si or 
		p | Sj must be true.
	
	Idea: 
		Naively, we will try all possibilites
		of set. Take the first sample case as
		as an example:
		
		3 2           (n, p)  
		1 2           (l1, r1) (r1 - l1 + 1 = 2)
		420 421       (l2, r2) (r2 - l2 + 1 = 2)
		420420 420421 (l3, r3) (r3 - l2 + 1 = 2)
		
		Then there will be 2x2x2 (Don't forget combinatorics) 
		possible set which are,
		
		S1   S2    S3   (Si = element-i)
		(1, 420, 420420)
		(1, 420, 420421)
		(1, 421, 420420)
		(1, 421, 420421)
		(2, 420, 420420)
		(2, 420, 420421)
		(2, 421, 420420)
		(2, 421, 420421)
		
		for every pair in any set which p | Si.Sj
		will get $2000. Notice that, we could
		calculate each pair separately from it's
		set.
		
		Focus at (1, 420) which is a possible
		pair of S1 and S2. This pair is one of
		the pair which get $2000 and it occurs
		at 2 possible set, which makes sense
		(by combinatorics again) cause there are
		only 2 possible value for S3.
		
		Next, by observation 1. The pair of Si
		and Sj will be divisible by p. If p | Si,
		or p | Sj or both true. Then let's assume
		the possible value for Si is in range
		li <= Si <= ri. Also for Sj is in range
		lj <= Sj <= rj (We know that it is
		the l, r given in the task). Also let's
		say when the number S chosen is divisible
		by p is D (Divisble) and which not is ND (Not Divisible).
		Then to make a pair of Si and Sj which
		is divisible by p we can have this combination
		below,
		
		Si Sj
	  1,Di NDj (We choose Si which is divisible by p)
	  2.NDi Dj (We choose Sj which is divisible by p)
	  3.Di Dj (We choose both to be divisible by p)
	  
	  	To know how many D and ND are there
	  	in range l, r we can do this,
	  	
	  	total = r - l + 1
	  	D = floor(r/p) + ceil(l/p)
	  	  = floor(r/p) + floor((l + (p - 1))/p)
	  	ND = total - D;
	  	
	  	Know for every Si and Sj (Remember that i and j must be neighbor)
	  	We know how many pairs where the pair
	  	of Si and Sj will get $2000. Know the
	  	question is how to know how often
	  	the Si, Sj pair will exist in any possible
	  	set? Just combinatorics again :v
	  	(We find all possible set could be made
	  	without Si and Sj).
	  	
	  	At last, we just need to combine everything
	  	that has been discussed this far
	  	(For the expected value just learn probability :) . 
	  	In this implementation for the intermediate
	  	counting, we will us long double, else
	  	we may get NaN ( like me :) ) as the
	  	value may get quite large for long long maybe.
		
*/

#include <bits/stdc++.h>
using namespace std;


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
	ll n,p;
	cin >> n >> p;
	
	vector<ld> rg(n), d(n), nd(n);
	ll tot = 1;
	for(int i = 0; i < n; ++i) {
		ll l, r;
		cin >> l >> r;
		
		rg[i] = r - l + 1; tot *= rg[i];
		ll di = (r/p) - ( (l + (p - 1))/p ) + 1;
		d[i] = di;
		nd[i] = rg[i] - d[i];
	}
	
	ld sum = 0;
	for(int i = 0; i < n; ++i) {
		ll p1 = i, p2 = (i + 1)%n;
		ld M = tot; M/=rg[p1]; M/=rg[p2];
		
		ld res = 0;
		res += (d[p1]*nd[p2]*M*2000.0);
		res += (nd[p1]*d[p2]*M*2000.0);
		res += (ld)(d[p1]*d[p2]*M*2000.0);
		
		sum += res/tot;
	}
	
	ld ans = sum;
	
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	cout << ans << endl;
	return 0;
}
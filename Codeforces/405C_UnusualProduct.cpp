/*
	Author: MikiMiku
	
	Observation:
		1. Every change/flip to index (i, j)
		where i != j will never effect final solution
		2. Only index (i, j) where i == j will
		have effect on final solution
		
		To see why things above true, let's
		work on an example, a 3 x 3 matrix. It's
		unusual product is 
		((i, j) means value at row i and column j)
		
		(0,0)*(0,0) + (0,1)*(1,0) + (2,0)*(0,2)
		+ (1,0)*(0,1) + (1,1)*(1,1) + (1,2)*(2,1)
		+ (2,0)*(0,2) + (2.1)*(1,2) + (2,2)*(2,2)
		
		which is the same as,
		
		(0,0)*(0,0) + (1,1)*(1,1) + (2,2)*(2,2)
		+ 2*( (0,1)*(1,0) + (1,2)*(2,1) + (2,0)*(0,2) )
		
		when modded by 2, we left with
		
		(0,0)*(0,0) + (1,1)*(1,1) + (2,2)*(2,2) + 0
		
		3. -1 === 1 (mod 2) (=== is congruent to)
		
	Idea: 
		By our observation then it means that
		every flipping query (at row i or column i) 
		is just a flip at element (i, i). Use observation 3
		to make our life easier.
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

	int n;
	cin >> n;
	
	ll c = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			int u;
			cin >> u;
			if(i == j) c += u;
		}
	}
	c %= 2;
	
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int ty;
		cin >> ty;
		
		int x;
		if(ty == 1) {
			cin >> x;
			c++; c %= 2;
		} else if(ty == 2) {
			cin >> x;
			c++; c %= 2;
		} else {
			cout << c;
		}
	}
	return 0;
}
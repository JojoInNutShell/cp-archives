/*
	Author: MikiMiku
	
	Observation:
		1. To make the algorithm produce incorrect
		answer we need N >= 6. As we could construct
		a tree with evencnt >= 3 and oddcnt >= 3 but
		the vertex cover set with size 2 only.
		(Making vertex cover set with size 1 means
		that the tree must have a star-like structure,
		which couldn't break the algorithm).
		
		We will construct the tree this way, (If N = 6)
		    1
		    |
		    2 (2's child will be all odd numbered nodes >= 3)
		   /\
		  3  5 (3's child will be all even numbered nodes >= 4)
		 /\
	    4 6
	    
	    This way 2 and 3 will always be a sufficient
	    vertex cover with evencnt and oddcnt >= 3.
	    (Because the even numbered nodes must
	    be counted in evencnt and the odd numbered
	    nodes must be counted in oddcnt).
	    
	    2. To make the algorithm produce correct
	    answer we will just make a path with N
	    vertices.
	    
	Idea: 
		Just implement like what has been discussed
		in observation.
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
	
	vector<ii> ans1;
	if(n >= 6) {
		ans1.eb(1,2);
		for(int i = 3; i <= n; i += 2) ans1.eb(2, i);
		for(int i = 4; i <= n; i += 2) ans1.eb(3, i);
	}
	
	vector<ii> ans2;
	for(int i = 1; i < n; ++i) {
		ans2.eb(i, i + 1);
	}
	
	if(ans1.empty()) {
		cout << -1 << endl;
	} else {
		for(int i = 0; i < n - 1; ++i) {
			cout << ans1[i].fi << " " << ans1[i].se << endl;
		}
	}
	
	for(int i = 0; i < n - 1; ++i) {
		cout << ans2[i].fi << " " << ans2[i].se << endl;
	}
	return 0;
}
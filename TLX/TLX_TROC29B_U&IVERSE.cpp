/*
	Author: MikiMiku
	
	Observation:
		1. Let's say that we have N monument and
		we trip from monument 1 to monument N in order.
		Hence, the formula for the total distance is
		
		|x1 - x2| + |x2 - x3| + ... + |x(N-1) - xN| +
		|y1 - y2| + |y2 - y3| + ... + |y(N-1) - yN|
		
		To know if it is odd or even,
		
		(|x1 - x2| + |x2 - x3| + ... + |x(N-1) - xN| +
		|y1 - y2| + |y2 - y3| + ... + |y(N-1) - yN|) (mod 2)
		
		but,
		
		-x === x (mod 2) (=== is congruent to)
		
		Hence, we may change the formula to,
		
		(|x1 + x2| + |x2 + x3| + ... + |x(N-1) + xN| +
		|y1 + y2| + |y2 + y3| + ... + |y(N-1) + yN|) (mod 2)
		
		(x1 + 2*x2 + 2*x3 + ... + 2*x(N-1) + xN +
		y1 + 2*y2 + 2*y3 + ... + 2*y(N-1) + yN) (mod 2)
		
		(x1 + xN + y1 + yN) (mod 2)
		
		At last, we could see that the parity of
		the trip that we choose just depend
		on the coordinate of the first and the last
		monument that we chose.
		
	Idea: 
		By observation 1, we just need to check
		for some combination that exist in the list.
		
		The combinations that we need to check are,
		(x1 + xN + y1 + yN)
		-> 1 + 0 + 0 + 0
		-> 0 + 1 + 0 + 0
		-> 1 + 1 + 1 + 0
		-> 1 + 1 + 0 + 1
		
		This can be easily done by a little mapping.
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
vector<ii> v1({{1,0}, {0,1}, {1,1}, {1,1}});
vector<ii> v2({{0,0}, {0,0}, {1,0}, {0,1}});

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	
	bool xy[2][2];
	memset(xy, 0, sizeof(xy));
	
	for(int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		xy[x % 2][y % 2] = 1;
	}
	
	for(int i = 0; i < 4; ++i) {
		if(xy[v1[i].fi][v1[i].se] && xy[v2[i].fi][v2[i].se]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}
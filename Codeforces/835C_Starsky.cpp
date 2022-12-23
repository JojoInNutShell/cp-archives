/*
	Author: MikiMiku
	
	Idea: 
		The important thing here is to notice that
		the coordinate value, and brightness value
		was quite small. Hence here, the idea
		is that we make a 2D prefix sum.
		
		But it won't be inaf because for every 
		different brightness value in the rectange 
		should be treated differently (or there is no
		math formulation such that we could handle
		all of those different brightness value
		in the rectangle easily).
		
		This will add one more parameter to
		our 2D Prefix Sum which is the brighness
		value. So our 2D prefix sum will be,
		
		prens[b][x][y]
		
		"prens" is the name of the variable for
		the 2D prefix sum which will contain
		value of how many stars are there in
		rectangle (1,1) to (x,y) with brightness b.
		
		The rest is just implementing the 2D
		Prefix sum.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int ns[17][107][107];
int prens[17][107][107];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, q, c;
	cin >> n >> q >> c; c++;
	
	memset(ns, 0, sizeof(ns));
	
	for(int i = 0; i < n; ++i) {
		int x, y, s;
		cin >> x >> y >> s;
		ns[s][x][y] += 1;
	}
	
	memset(prens, 0, sizeof(prens));
	
	for(int k = 0; k <= 10; ++k) {
		for(int i = 1; i < 102; ++i) {
			for(int j = 1; j < 102; ++j) {
				prens[k][i][j] = prens[k][i][j - 1] + prens[k][i - 1][j] - prens[k][i - 1][j - 1] + ns[k][i][j];
			}
		}
	}
	
	for(int i = 0; i < q; ++i) {
		int t, xld, yld, xru, yru;
		cin >> t >> xld >> yld >> xru >> yru;
		
		ll ans = 0;
		for(int j = 0; j <= 10; ++j) {
			ll tot = prens[j][xru][yru] - prens[j][xld - 1][yru] - prens[j][xru][yld - 1] + prens[j][xld - 1][yld - 1];
			ans += ((j + t)%c)*tot;
		}
		
		cout << ans << endl;
	}
	return 0;
}
/*
	Author: MikiMiku
	
	Idea: 
		Let's say that we know the score of each
		team which are x1, x2, and x3.
		
		Then, below holds
		
		x1 + x2 + x3 = k......1
		|x1 - x2| = d1........2
		|x2 - x3| = d2........3
		
		We already know k, d1, and d2 then with
		only three unknowns we may solve the
		equations above and find x1, x2, and x3.
		
		We will divide to 4 cases :
		1. x1 >= x2 and x2 >= x3
		
		x1 + x2 + x3 = k......1
		x1 - x2 = d1........2
		x2 - x3 = d2........3
		
		2. x1 >= x2 and x3 >= x2
		
		x1 + x2 + x3 = k......1
		x1 - x2 = d1........2
		x3 - x2 = d2........3
		
		3. x2 >= x1 and x2 >= x3
		
		x1 + x2 + x3 = k......1
		x2 - x1 = d1........2
		x2 - x3 = d2........3
		
		4. x2 >= x1 and x3 >= x2
		
		x1 + x2 + x3 = k......1
		x2 - x1 = d1........2
		x3 - x2 = d2........3
		
		Just solve equations above for each cases.
		Note that for x1, x2, and x3 to be a
		valid solution, the following must true :
		
		1. x <= n/3 (Else, we can't distribute points evenly)
		2. x >= 0 (Negative win can't be possible)
		3. x must be an integer (there isn't exist a half, a quarter or only some fraction of win)
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
	int T;
	cin >> T;
	while(T--) {
		ll n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		
		ll x1, x2, x3;
		vector<vector<ll>> cand;
		
		x1 = k + 2*d1 + d2;
		x3 = k - d1 - 2*d2;
		if(x1%3==0 && x3%3==0) {
			x1 /= 3;
			x3 /= 3;
			x2 = k - x1 - x3;
			
			cand.pb({x1, x2, x3});
		}
		
		x1 = k + 2*d1 - d2;
		x3 = k - d1 + 2*d2;
		if(x1%3==0 && x3%3==0) {
			x1 /= 3;
			x3 /= 3;
			x2 = k - x1 - x3;
			
			cand.pb({x1, x2, x3});
		}
		
		
		x2 = k + d1 + d2;
		x3 = k + d1 - 2*d2;
		if(x2%3 == 0 && x3%3 == 0) {
			x2 /= 3;
			x3 /= 3;
			x1 = k - x2 - x3;
			
			cand.pb({x1, x2, x3});
		}
		
		x2 = k + d1 - d2;
		x3 = k + d1 + 2*d2;
		if(x2%3 == 0 && x3%3 == 0) {
			x2 /= 3;
			x3 /= 3;
			x1 = k - x2 - x3;
			
			cand.pb({x1, x2, x3});
		}
 		
 		if(n%3 != 0) {
 			cout << "no" << endl;
 			continue;
 		} n/=3;
 		
 		bool found = false;
 		for(int i = 0; i < sza(cand); ++i) {
 			bool ok = true;
 			for(int j = 0; j < 3; ++j) {
 				if(cand[i][j] < 0 || cand[i][j] > n) {
 					ok = false;
 					break;
 				}
 			}
 			found |= ok;
 		}
 		
 		if(found) {
 			cout << "yes" << endl;
 		} else {
 			cout << "no" << endl;
 		}
	}
	return 0;
}
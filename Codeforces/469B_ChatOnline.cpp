#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
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
//........................................................................
vector<ii> x, z;

bool isOverlap(ii p1, ii p2) {
	if(p2 < p1) swap(p1, p2);
	int lo = min(p1.se, p2.fi);
	if(lo == p2.fi) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int a,b, l,r,i1,i2;
	cin >> a >> b >> l >> r;
	for(int i = 0; i < a; ++i) {
		cin >> i1 >> i2;
		z.pb({i1, i2});
	}
	for(int i = 0; i < b; ++i) {
		cin >> i1 >> i2;
		x.pb({i1, i2});
	}
	int mo = 0;
	bool isMo;
	for(int t = l; t <= r; ++t) {
		isMo = false;
		for(auto p1 : z) {
			for(auto p2 : x) {
				ii p3 = {p2.fi + t, p2.se + t};
				if(isOverlap(p1, p3)) {
					isMo = true;
					break;
				}
			}
			if(isMo) break;
		}
		if(isMo) ++mo;
	}
	cout << mo;
	return 0;
}
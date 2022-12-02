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
struct comp {
	bool operator()(const ii& p1, const ii& p2) const {
		if(p1.fi == p2.fi) {
			return p1.se < p2.se;
		} else {
			return p1.fi > p2.fi;
		}
	}
};

bool cmp(ii p1, ii p2) {
	if(p1.fi == p2.fi) {
		return p1.se < p2.se;
	} else {
		return p1.fi > p2.fi;
	}
}

multimap<ii, int, comp> book;
multimap<int, int> tablist;
multimap<int, int> ans;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int ord;
	cin >> ord;
	int c, p;
	for(int i = 1; i <= ord; ++i) {
		cin >> c >> p;
		book.insert({{p, c}, i});
	}
	int nt, tsz;
	cin >> nt;
	for(int i = 1; i <= nt; ++i) {
		cin >> tsz;
		tablist.insert({tsz, i});
	}
	int mo = 0;
	for(auto p : book) {
		auto it = tablist.lower_bound(p.fi.se);
		if(it != tablist.end()) {
			ans.insert({p.se, (*it).se});
			mo += p.fi.fi;
			tablist.erase(it);
		}
	}
	cout << sza(ans) << " " << mo << endl;
	for(auto p : ans) {
		cout << p.fi << " " << p.se << endl;
	}
	return 0;
}
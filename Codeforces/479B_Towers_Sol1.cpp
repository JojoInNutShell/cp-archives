#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
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
array<vector<int>, 20006> to;
map<int, int> mint;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		mint[a]++;
		to[a].pb(i + 1);
	}
	vector<ii> lm;
	for(int i = 0; i < k; ++i) {
		if(mint.size() == 1) break;
		int st = (*(mint.begin())).fi;
		int th = (*(prev(mint.end()))).fi;
		cerr << st << " " << th << endl;
		lm.pb({to[th].back(), to[st].back()});
		int bth = to[th].back(), bst = to[st].back();
		to[th].pop_back(); to[st].pop_back();
		to[th - 1].pb(bth);
		to[st + 1].pb(bst);
		mint[th]--; mint[st]--;
		if(mint[th] <= 0) mint.erase(th);
		if(mint[st] <= 0) mint.erase(st);
		mint[th - 1]++; mint[st + 1]++;
	}
	int st = (*(mint.begin())).fi;
	int th = (*(prev(mint.end()))).fi;
	int dif = th - st;
	int c = sza(lm);
	cout << dif << " " << c << endl;
	for(auto p : lm) {
		cout << p.fi << " " << p.se << endl;
	}
	return 0;
}
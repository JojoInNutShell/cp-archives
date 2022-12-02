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
//........................................................................
array<ii, 200006> st;
int n;
string s;

int left(int p) { return (p << 1); }
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {
	if(L == R) {
		if(s[L] == '(') {
			st[p].fi = 1;
		} else {
			st[p].se = 1;
		}
	} else {
		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);
		int mn = min(st[left(p)].fi, st[right(p)].se);
		st[p].fi = st[right(p)].fi + st[left(p)].fi - mn;
		st[p].se = st[right(p)].se + st[left(p)].se - mn;
	}
}

void update(int p, int L, int R, int idx) {
	int i = idx, j = idx;
	if(L > j || R < i) {
		return;
	} else if(i <= L && R <= j) {
		if(st[p].fi) {
			st[p].fi = 0;
			st[p].se = 1;
		} else {
			st[p].fi = 1;
			st[p].se = 0;
		}
	} else {
		update(left(p), L, (L + R)/2, idx);
		update(right(p), (L + R)/2 + 1, R, idx);
		int mn = min(st[left(p)].fi, st[right(p)].se);
		st[p].fi = st[right(p)].fi + st[left(p)].fi - mn;
		st[p].se = st[right(p)].se + st[left(p)].se - mn;
	}
}

bool check() {
	if(st[1].fi == 0 && st[1].se == 0) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int tc = 1;
	while(cin >> n) {
		cout << "Test " << tc++ << ":" << endl;
		cin >> s;
		st.fill({0, 0});
		build(1, 0, n - 1);
		int m;
		cin >> m;
		int k;
		for(int i = 0; i < m; ++i) {
			cin >> k;
			if(k == 0) {
				if(check()) {
					cout << "YES";
				} else {
					cout << "NO";
				}
				cout << endl;
			} else {
				update(1, 0, n - 1, k - 1);
			}
		}
	}
	return 0;
}
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
//........................................................................
int a[200006];
unordered_map<int, int> st[800006];

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }

void build(int p, int l, int r) {
	if(l == r) {
		st[p][a[l]]++;
	} else {
		build(left(p), l, (l + r)/2);
		build(right(p), (l + r)/2 + 1, r);
		for(auto pi : st[left(p)]) {
			st[p][pi.fi] += pi.se;
		}
		for(auto pi : st[right(p)]) {
			st[p][pi.fi] += pi.se;
		}
	}
}

int kth(int p, int L, int R, int val, int le) {
	if(L == R) {
		if(st[p][val] < le) {
			return -1;
		} else {
			return L + 1;
		}
	} else {
		if(st[left(p)][val] >= le) {
			return kth(left(p), L, (L + R)/2, val, le);
		} else {
			return kth(right(p), (L + R)/2 + 1, R, val, le - st[left(p)][val]);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, nq;
	cin >> n >> nq;
	for(int i = 0; i < n; ++i) cin >> a[i];
	build(1, 0, n - 1);
	int x, k;
	for(int i = 0; i < nq; ++i) {
		cin >> x >> k;
		cout << kth(1, 0, n - 1, x, k) << endl;
	}
	return 0;
}
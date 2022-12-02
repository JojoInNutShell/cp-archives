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
vector<int> arr, st;

int left(int p) { return p << 1; }
int right(int p) { return (p << 1) + 1;} 

void build(int p, int L, int R) {
	if(L == R) st[p] = arr[L];
	else {
		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void update(int p, int L, int R, int i, int j, int val) {
	if(L > j || R < i) return;
	else if(i <= L && R <= j) {
		st[p] += val;
	} else {
		update(left(p), L, (L + R)/2, i, j, val);
		update(right(p), (L + R)/2 + 1, R, i, j, val);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void update0(int p, int L, int R, int i, int j) {
	if(L > j || R < i) return;
	else if(i <= L && R <= j) {
		cout << st[p] << endl;
		st[p] = 0;
	} else {
		update0(left(p), L, (L + R)/2, i, j);
		update0(right(p), (L + R)/2 + 1, R, i, j);
		st[p] = st[left(p)] + st[right(p)];
	}
}

int rsq(int p, int L, int R, int i, int j) {
	if(L > j || R < i) return -1;
	else if(i <= L && R <= j) {
		return st[p];
	} else {
		int p1 = rsq(left(p), L, (L + R)/2, i, j);
		int p2 = rsq(right(p), (L + R)/2 + 1, R, i, j);
		//cerr << p1 << " " << p2 << endl;
		
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return p1 + p2;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cout << "Case " << tc << ":" << endl;
		int n, q;
		cin >> n >> q;
		arr.clear(); arr.reserve(n); st.reserve(4*n);
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		build(1, 0, n - 1);
		int qn, i, j;
		for(int nq = 0; nq < q; ++nq) {
			cin >> qn;
			if(qn == 1) {
				cin >> i;
				update0(1, 0, n - 1, i, i);
			}
			if(qn == 2) {
				cin >> i >> j;
				update(1, 0, n - 1, i, i, j);
			}
			if(qn == 3) {
				cin >> i >> j;
				cout << rsq(1, 0, n - 1, i, j) << endl;
			}
		}
	}
	return 0;
}
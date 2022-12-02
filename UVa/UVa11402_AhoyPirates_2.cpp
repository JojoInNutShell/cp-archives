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
int st[5024000];
char lazy[5024000];
bitset<5024000> marked;
string arr;
int n, sz;
int left(int n) { return (n << 1); }
int right(int n) { return (n << 1) + 1;}

void changeState(int p) {
	if(lazy[p] == 'I') lazy[p] = 'X';
	else if(lazy[p] == 'X') lazy[p] = 'I';
	else if(lazy[p] == 'F') lazy[p] = 'E';
	else if(lazy[p] == 'E') lazy[p] = 'F';
}

void build(int p, int L, int R) {
	if(L == R) {
		st[p] = arr[L] - '0';
	} else {
		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);
		st[p] = st[left(p)] + st[right(p)];
	}
}

void push(int p, int L, int R) {
	if(lazy[p] == 'E') {
		st[p] = 0;
	} else if(lazy[p] == 'F') {
		st[p] = R - L + 1;
	} else if(lazy[p] == 'I') {
		st[p] = (R - L + 1) - st[p];
	}
	if(L != R) {
		if(lazy[p] == 'I') {
			changeState(left(p));
			changeState(right(p));
		} else {
			lazy[left(p)] = lazy[p];
			lazy[right(p)] = lazy[p];
		}
	}
	lazy[p] = 'X';
}

void update(int p, int L, int R, int i, int j, char val) {
	if(lazy[p] != 'X') {
		push(p, L, R);
	}
	if(L > j || R < i) return;
	if(i <= L && R <= j) {
		if(val == 'F') {
			st[p] = (R - L + 1);
		}
		if(val == 'E') {
			st[p] = 0;
		}
		if(val == 'I') {
			st[p] = (R - L + 1) - st[p];
		}
		if(L != R) {
			if(val == 'I') {
				changeState(left(p));
				changeState(right(p));
			} else {
				lazy[left(p)] = val;
				lazy[right(p)] = val;
			}
		}
		return;
	} else {
		update(left(p), L, (L + R)/2, i, j, val);
		update(right(p), (L + R)/2 + 1, R, i, j, val);
		st[p] = st[left(p)] + st[right(p)];
	}
}

int rsq(int p, int L, int R, int i, int j) {
	if(lazy[p] != 'X') {
		push(p, L, R);
	}
	if(L > j || R < i) return -1;
	if(i <= L && R <= j) {
		return st[p];
	} else {
		int p1 = rsq(left(p), L, (L + R)/2, i, j);
		int p2 = rsq(right(p), (L + R)/2 + 1, R, i, j);
		
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
		marked.reset();
		arr.clear();
		cout << "Case " << tc << ":" << endl;
		int m;
		cin >> m;
		int k;
		string s;
		for(int i = 0; i < m; ++i) {
			cin >> k >> s;
			for(int j = 0; j < k; ++j) {
				arr += s;
			}
		}
		//cerr << arr << endl; 
		sz = sza(arr);
		//cerr << sz << endl;
		build(1, 0, sz - 1);
		for(int i = 1; i <= 4*sz; ++i) lazy[i] = 'X';
		int nq;
		cin >> nq;
		char ch;
		int i, j, ask = 1;
		for(int k = 0; k < nq; ++k) {
			cin >> ch >> i >> j;
			if(ch == 'F') {
				update(1, 0, sz - 1, i, j, 'F');
			} else if(ch == 'E') {
				update(1, 0, sz - 1, i, j, 'E');
			} else if(ch == 'I') {
				update(1, 0, sz - 1, i, j, 'I');
			} else {
				cout << "Q" << ask++ << ": " << rsq(1, 0, sz - 1, i, j) << endl;
			}
		}
	}
	return 0;
}
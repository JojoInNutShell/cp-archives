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
int st[500006], arr[100006];
int n, k;
int left(int n) { return (n << 1); }
int right(int n) { return (n << 1) + 1;}

void build(int p, int L, int R) {
	if(L == R) {
		if(arr[L] > 0) {
			st[p] = 1;
		} else if(arr[L] < 0) {
			st[p] = -1;
		} else {
			st[p] = 0;
		}
	} else {
		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);
		st[p] = st[left(p)] * st[right(p)];
	}
}

void update(int p, int L, int R, int pos, int val) {
	int i, j; i = pos, j = pos;
	if(L > j || R < i) return;
	else if(i <= L && R <= j) {
		if(val > 0) {
			st[p] = 1;
		} else if(val < 0) {
			st[p] = -1;
		} else {
			st[p] = 0;
		}
	} else {
		update(left(p), L, (L + R)/2, pos, val);
		update(right(p), (L + R)/2 + 1, R, pos, val);
		st[p] = st[left(p)] * st[right(p)];
	}
}

int rpq(int p, int L, int R, int i, int j) {
	if(L > j || R < i) return 404;
	else if(i <= L && R <= j) {
		return st[p];
	} else {
		int p1 = rpq(left(p), L, (L + R)/2, i, j);
		int p2 = rpq(right(p), (L + R)/2 + 1, R, i, j);
		
		if(p1 == 404) return p2;
		if(p2 == 404) return p1;
		return p1*p2;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	while(cin >> n >> k) {
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		build(1, 0, n - 1);
		char ch;
		int pos, val;
		for(int nq = 0; nq < k; ++nq) {
			cin >> ch >> pos >> val;
			if(ch == 'C') {
				if(val > 0) {
					update(1, 0, n - 1, pos - 1, 1);
				} else if(val < 0) {
					update(1, 0, n - 1, pos - 1, -1);
				} else {
					update(1, 0, n - 1, pos - 1, 0);
				}
			} else {
				int res = rpq(1, 0, n - 1, pos - 1, val - 1);
				if(res == 0) {
					cout << 0;
				} else if(res == 1) {
					cout << '+';
				} else {
					cout << '-';
				}
			}
		}
		cout << endl;
	}
	return 0;
}
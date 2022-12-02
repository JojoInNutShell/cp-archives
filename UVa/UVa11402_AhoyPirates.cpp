#include <array>
#include <vector>
#include <iostream>
using namespace std;

#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int FMOD = 998244353; 
const ll INF = 1e9;
const ld EPS = 1e-9;

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................
int st[5024006], arr[5024006];
int n;
int left(int p) { return p << 1; };
int right(int p) { return (p << 1) + 1; }
void build(int i, int L, int R) {
	if(L == R) st[i] = arr[L];
	else {
		build(left(i), L, (L + R)/2);
		build(right(i), (L + R)/2 + 1, R);
		st[i] = st[left(i)] + st[right(i)];
	}
}
int rsq(int idx, int L, int R, int i, int j) {
	//cerr << L << " " << R << " ";
	if(R < i || L > j) return -1;
	else if(L >= i && R <= j) return st[idx];
	else {
		int p1 = rsq(left(idx), L, (L + R)/2, i, j);
		int p2 = rsq(right(idx), (L + R)/2 + 1, R, i, j);
				
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return p1 + p2;
	}
}
void updateRange(int idx, int L, int R, int i, int j, int new_val) {
	if(L > j || R < i) return;
	else if(L == R) {
		arr[L] = new_val;
		st[idx] = arr[L];
	} else {
		updateRange(left(idx), L, (L + R)/2, i, j, new_val);
		updateRange(right(idx), (L + R)/2 + 1, R, i, j, new_val);
		st[idx] = st[left(idx)] + st[right(idx)];
	}
}
void updateRangeXor(int idx, int L, int R, int i, int j) {
	if(L > j || R < i) return;
	else if(L == R) {
		arr[L] ^= 1;
		st[idx] ^= 1;
	} else {
		updateRangeXor(left(idx), L, (L + R)/2, i, j);
		updateRangeXor(right(idx), (L + R)/2 + 1, R, i, j);
		st[idx] = st[left(idx)] + st[right(idx)];
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cout << "Case " << tc << ":" << endl;
		int m;
		cin >> m;
		
		int t, id = 0;
		n = 0;
		string s;
		for(int i = 0; i < m; ++i) {
			cin >> t >> s;
			n += (t*sza(s));
			for(int j = 0; j < t; ++j) {
				for(auto ch : s) {
					arr[id++] = ch - '0';
				}
			}
		} 
		//QUERY TIME
		build(1, 0, n - 1);
		int nq, l, r, cnt = 1;
		char c;
		cin >> nq;
		for(int i = 0; i < nq; ++i) {
			cin >> c >> l >> r;
			if(c == 'F') {
				updateRange(1, 0, n - 1, l, r, 1);
			} else if(c == 'E') {
				updateRange(1, 0, n - 1, l, r, 0);
			} else if(c == 'I') {
				updateRangeXor(1, 0, n - 1, l, r);
			} else {
				cout << "Q" << cnt++ << ": " << rsq(1, 0, n - 1, l, r) << endl;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int arr[100006];
deque<ii> st[500006];
int n, idx, ans_idx;
deque<ii> ans;

int left(int p) { return (p << 1); }
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {
	if(L == R) {
		st[p] = {{1, arr[L]}};
	} else {
		build(left(p), L, (L + R)/2);
		build(right(p), (L + R)/2 + 1, R);
		st[p].clear();
		int i;
		int szlp = sza(st[left(p)]);
		//cerr << L << " " << R << endl << endl;
		for(i = 0, idx = 0; idx < szlp; ++idx) {
			if(idx == 0) {
				st[p].push_back(st[left(p)][idx]);
			} else {
				if(st[p][i].se == st[left(p)][idx].se) {
					st[p][i].fi += st[left(p)][idx].fi;
				} else {
					st[p].push_back(st[left(p)][idx]);
					i++;
				}
			}
		}
		int szrp = sza(st[right(p)]);
		for(idx = 0; idx < szrp; ++idx) {
			if(st[p][i].se == st[right(p)][idx].se) {
				st[p][i].fi += st[right(p)][idx].fi;
			} else {
				st[p].push_back(st[right(p)][idx]);
				i++;
			}
		}
		int szp = sza(st[p]);
		if(szp > 3) {
			sort(st[p].begin() + 1, st[p].end() - 1);
			st[p].erase(st[p].begin() + 1, st[p].end() - 2);	
		}
		/*
		for(auto v : st[p]) {
			cerr << v.fi << " " << v.se << endl;
		}
		cerr << endl;
		*/
	}
}

void rmq(int p, int L, int R, int i, int j) {
	if(L > j || R < i) return;
	else if(i <= L && R <= j) {
		for(int i = 0; i < sza(st[p]); ++i) {
			if(ans_idx == -1) ans.push_back(st[p][i]), ans_idx++;
			else {
				if(ans[ans_idx].se == st[p][i].se) {
					ans[ans_idx].fi += st[p][i].fi;
				} else {
					ans.push_back(st[p][i]);
					ans_idx++;
				}
			}
			//cerr << st[p][i].fi << " " << st[p][i].se << endl;
		}
	} else {
		rmq(left(p), L, (L + R)/2, i, j);
		rmq(right(p), (L + R)/2 + 1, R, i, j);
		return;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int q;
	while(cin >> n >> q) {
		if(n == 0) break;
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		build(1, 0, n - 1);
		int i, j;
		for(int k = 0; k < q; ++k) {
			cin >> i >> j;
			//cerr << i << " " << j << endl << endl;
			ans.clear(); ans_idx = -1;
			rmq(1, 0, n - 1, i - 1, j - 1);
			int hi = -1;
			for(auto p : ans) {
				//cout << p.fi << " " << p.se << endl;
				hi = max(hi, p.fi);
			}
			cout << hi << endl;
			//cerr << endl;
		}
	}
	
	return 0;
}
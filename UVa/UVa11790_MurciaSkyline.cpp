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
int h[MAX_N], w[MAX_N], tablis[MAX_N], tablds[MAX_N];

int n;

int lis(int m) {
	if(tablis[m] != -1) return tablis[m];
	if(m == 0) return tablis[m] = w[m];
	else {
		int mx = w[m];
		for(int i = 0; i < m; ++i) {
			if(h[i] < h[m]) {
				mx = max(mx, lis(i) + w[m]);
			}
		}
		return tablis[m] = mx;
	}
}

int lds(int m) {
	if(tablds[m] != -1) return tablds[m];
	if(m == n - 1) return tablds[m] = w[n - 1];
	else {
		int mx = w[m];
		for(int i = m + 1; i < n; ++i) {
			if(h[m] > h[i]) {
				mx = max(mx, lds(i) + w[m]);
			}
		}
		return tablds[m] = mx;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int curt = 1; curt <= T; ++curt) {
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> h[i];
		}
		for(int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		memset(tablis, -1, sizeof(tablis));
		memset(tablds, -1, sizeof(tablds));
		int inc = -1, dc = -1;
		for(int i = n - 1; i >= 0; --i) {
			inc = max(inc, lis(i));
		}
		for(int i = 0; i < n; ++i) {
			dc = max(dc, lds(i));
		}
		/*
		for(int i = 0; i < n; ++i) {
			cerr << tablis[i] << " ";
		}
		cerr << endl;
		for(int i = 0; i < n; ++i) {
			cerr << tablds[i] << " ";
		}
		cerr << endl;
		*/
		cout << "Case " << curt << ". ";
		if(inc >= dc) {
			cout <<  "Increasing (" << inc << "). " << "Decreasing (" << dc << ")." << endl;
		} else {
			cout <<  "Decreasing (" << dc << "). " << "Increasing (" << inc << ")." << endl;
		}
	}
	return 0;
}
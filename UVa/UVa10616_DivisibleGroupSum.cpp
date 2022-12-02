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
array<int, 206> arr;
int tab[206][16][26];
int n, q;

int dp(int d, int m) {
	memset(tab, 0, sizeof(tab));
	tab[0][0][0] = 1;
	int tmp;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			for(int k = 0; k < d; ++k) {
				tmp = (arr[i] + k) % d;
				if(tmp < 0) tmp += d;
				tab[i][j][k] += tab[i - 1][j][k];
				if(j) {
					tab[i][j][k] += tab[i - 1][j - 1][tmp];
				}
			}
		}
	}
	for(int j = 0; j <= m; ++j) {
		cerr << "Layer " << j << endl;
		for(int i = 0; i <= n; ++i) {
			for(int k = 0; k < d; ++k) {
				cerr << tab[i][j][k] << " ";
			}
			cerr << endl;
		}
	}
	return tab[n][m][0];
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	arr[0] = 0;
	for(int curt = 1; cin >> n >> q; ++curt) {
		if(n == 0 && q == 0) break;
		
		for(int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		int d, m;
		cout << "SET " << curt << ":" << endl;
		for(int i = 0; i < q; ++i) {
			cin >> d >> m;
			cout << "QUERY " << i + 1 << ": " << dp(d, m) << endl;
		}
	}
	return 0;
}
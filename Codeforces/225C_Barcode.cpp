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
const int INF = 1e8;
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
array<array<array<int, 1006>, 1006>, 2> memo;
array<int, 1006> w, b;
int cumb = -1, cumw = -1;

void init() {
	w.fill(0); b.fill(0);
	for(auto& a : memo) {
		for(auto& ar : a) {
			ar.fill(INF);
		}
	}
}

int dp(int m, int x, int y) {
	for(int r = x; r <= m; ++r) {
		for(int k = 0; k < 2; ++k) {
			for(int i = x; i <= y; ++i) {
				if(r == x) {
					if(i == x) {
						if(k == 0) {
							if(cumw == -1) {
								cumw = 0;
								for(int c = 1; c <= x; ++c) {
									cumw += w[c];
								}
							}
							memo[k][r][i] = cumw;
						} else {
							if(cumb == -1) {
								cumb = 0;
								for(int c = 1; c <= x; ++c) {
									cumb += b[c];
								}
							}
							memo[k][r][i] = cumb;
						}
					} else {
						memo[k][r][i] = INF;	
					}
				} else {
					if(i == x) {
						if(k == 0) {
							int mn = INF;
							for(int c = x; c <= y; ++c) {
								mn = min(mn, memo[k ^ 1][r - x][c]);
							}
							int ctox = 0;
							for(int c = r - x + 1; c <= r; ++c) {
								ctox += w[c];
							}
							memo[k][r][i] = mn + ctox;
						} else {
							int mn = INF;
							for(int c = x; c <= y; ++c) {
								mn = min(mn, memo[k ^ 1][r - x][c]);
							}
							int ctox = 0;
							for(int c = r - x + 1; c <= r; ++c) {
								ctox += b[c];
							}
							memo[k][r][i] = mn + ctox;
						}
					} else {
						if(k == 0) {
							memo[k][r][i] = memo[k][r - 1][i - 1] + w[r];
						} else {
							memo[k][r][i] = memo[k][r - 1][i - 1] + b[r];
						}
					}
				}
			}
		}
	}
	int mn = INF;
	for(int k = 0; k < 2; ++k) {
		for(int i = x; i <= y; ++i) {
			mn = min(memo[k][m][i], mn);
		}
	}
	return mn;
}
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, x, y;
	init();
	cin >> n >> m >> x >> y;
	string s;
	for(int i = 0; i < n; ++i) {
		cin  >> s;
		for(int j = 1; j <= m; ++j) {
			if(s[j - 1] == '#') {
				b[j]++;
			} else {
				w[j]++;
			}
		}
	}
	cout << dp(m, x, y);
	return 0;
}
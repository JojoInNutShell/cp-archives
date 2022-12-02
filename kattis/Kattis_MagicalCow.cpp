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
int tab[56][1006];
int dayc[56];
int maxc, m, nq;

void dp() {
	for(int i = 1; i < 51; ++i) {
		for(int j = 1; j <= maxc; ++j) {
			if(j >= (maxc + 2)/2) {
				if(j % 2 == 0) {
					tab[i][j] = 2 * tab[i - 1][j] + tab[i - 1][j/2];
				} else {
					tab[i][j] = 2*tab[i - 1][j];
				}
			} else {
				if(j % 2 == 0) {
					tab[i][j] = tab[i - 1][j/2];
				} else {
					tab[i][j] = 0;
				}
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> maxc >> m >> nq;
	int t; 
	memset(tab, 0, sizeof(tab));
	memset(dayc, -1, sizeof(dayc));
	for(int i = 0; i < m; ++i) {
		cin >> t;
		tab[0][t]++;
	}
	dp();
	int q;
	for(int i = 0; i < nq; ++i) {
		cin >> q;
		int sum = 0;
		for(int j = 1; j <= maxc; ++j) {
			sum += tab[q][j];
		}
		cout << sum << endl;
	}
	return 0;
}
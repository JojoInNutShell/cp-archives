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
map<string, int> mapsi;
array<array<int, 56>, 56> adjMat;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, tc = 1;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		int id = 0;
		string s1, s2;
		int u, v;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) adjMat[i][i] = 0;
				else adjMat[i][j] = INF;
			}
		}
		mapsi.clear();
		for(int i = 0; i < m; ++i) {
			cin >> s1 >> s2;
			if(mapsi.find(s1) == mapsi.end()) {
				mapsi[s1] = id++;
			}
			if(mapsi.find(s2) == mapsi.end()) {
				mapsi[s2] = id++;
			}
			u = mapsi[s1]; v = mapsi[s2];
			adjMat[u][v] = 1;
			adjMat[v][u] = 1;
		}
		int mx = -1;
		for(int k = 0; k < n; ++k) {
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < n; ++j) {
					adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
					if(k == n - 1) mx = max(mx, adjMat[i][j]);
				}
			}
		}
		cout << "Network " << tc++ << ": ";
		if(mx == INF) {
			cout << "DISCONNECTED";
		} else {
			cout << mx;
		}
		cout << endl << endl;
	}
	return 0;
}
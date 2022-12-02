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
array<vector<int>, 106> adjList;
vector<pair<pair<int, int>, int>> edgeList;
array<int, 106> dist, w;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		if(n == -1) break;
		adjList.fill({});
		dist.fill(INF);
		int t, m;
		for(int i = 1; i <= n; ++i) {
			cin >> w[i] >> m;
			for(int j = 0; j < m; ++j) {
				cin >> t;
				adjList[i].pb(t);
			}
		}
		edgeList.clear();
		for(int i = 1; i <= n; ++i) {
			for(auto v : adjList[i]) {
				edgeList.pb({{i, v}, -w[v]});
			}
		}
		dist[1] = 0;
		for(int i = 0; i < n; ++i) {
			for(auto p : edgeList) {
				if(dist[p.fi.fi] == INF) continue;
				if(dist[p.fi.fi] + p.se < dist[p.fi.se] && dist[p.fi.fi] + p.se < 100) {
					dist[p.fi.se] = dist[p.fi.fi] + p.se;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(auto p : edgeList) {
				if(dist[p.fi.fi] + p.se < dist[p.fi.se] && dist[p.fi.fi] + p.se < 100) {
					dist[p.fi.se] = -INF;
				}
			}
		}
		if(dist[n] >= 100) {
			cout << "hopeless";
		} else {
			cout << "winnable";
		}
		cout << endl;
	}
	return 0;
}
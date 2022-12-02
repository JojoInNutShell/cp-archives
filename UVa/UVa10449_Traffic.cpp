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
array<int, 206> ndcost, dist;
vector<pair<pair<int, int>, int>> edgeList;

ll POW(ll a, ll b) {
	if(b == 0) return 1;
	ll half = POW(a, b/2);
	if(b % 2 == 1) {
		return half*half*a;
	} else {
		return half*half;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, tc = 1;
	while(cin >> n) {
		cout << "Set #" << tc++ << endl;
		for(int i = 1; i <= n; ++i) {
			cin >> ndcost[i];
		}
		int m;
		cin >> m;
		int u, v;
		edgeList.clear();
		for(int i = 0; i < m; ++i) {
			cin >> u >> v;
			edgeList.pb({{u, v}, POW(ndcost[v] - ndcost[u], 3)});
		}
		dist.fill(INF);
		dist[1] = 0;
		for(int i = 0; i < n; ++i) {
			for(auto p : edgeList) {
				if(dist[p.fi.fi] == INF) continue;
				if(dist[p.fi.fi] + p.se < dist[p.fi.se]) {
					dist[p.fi.se] = dist[p.fi.fi] + p.se;
				}
			}
		}
		for(int i = 0; i < n; ++i) {
			for(auto p : edgeList) {
				if(dist[p.fi.fi] + p.se < dist[p.fi.se]) {
					dist[p.fi.se] = -INF;
				}
			}
		}
		int nq, q;
		cin >> nq;
		for(int i = 0; i < nq; ++i) {
			cin >> q;
			if(dist[q] < 3 || dist[q] == INF) {
				cout << '?';
			} else {
				cout << dist[q];
			}
			cout << endl;
		}
	}
	return 0;
}
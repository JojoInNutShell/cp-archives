#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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
class UnionFind {
	private : vi p, rank;
	public :
	UnionFind(int n) {
		p.assign(n, 0); rank.assign(n, 0);
		for(int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}
	int findset(int u) {
		if(p[u] == u) {
			return p[u];
		} else {
			p[u] = findset(p[u]);
			return p[u];
		}
	}
	bool isSameSet(int i, int j) {return findset(i) == findset(j);}
	void UnionSet(int i, int j) {
		int parx = findset(i); int pary = findset(j);
		if(rank[parx] > rank[pary]) {
			p[pary] = parx;
		} else {
			p[parx] = pary;
			if(rank[parx] == rank[pary]) rank[pary]++;
		}
	}
};

multimap<int, pair<int, int>> edgeList;
array<vii, 106> adjList;
array<bool, 106> visited;
int root, globallo, vq1, vq2;

void init() {
	edgeList.clear();
	adjList.fill({});
	visited.fill(false);
}

void dfs(int u, int lo = -1) {
	visited[u] = true;
	if(u == vq2) {
		globallo = lo;
		return;
	}
	for(auto v : adjList[u]) {
		if(visited[v.se] == false) {
			dfs(v.se, max(lo, v.fi));
		}
	}
	if(u == root) {
		if(globallo == -1) {
			cout << "no path" << endl;
		} else {
			cout << globallo <<  endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, q, curt = 1;
	while(cin >> n >> m >> q) {
		if(n == 0 && m == 0 && q == 0) {
			break;
		} else {
			if(curt != 1) {
				cout << endl;
			}
		}
		init();
		int v1, v2, w;
		UnionFind UF(n + 3);
		for(int i = 0; i < m; ++i) {
			cin >> v1 >> v2 >> w;
			edgeList.insert(mp(w, mp(v1, v2)));
		}
		for(auto p : edgeList) {
			if(!UF.isSameSet(p.se.fi, p.se.se)) {
				UF.UnionSet(p.se.fi, p.se.se);
				adjList[p.se.fi].pb(mp(p.fi, p.se.se));
				adjList[p.se.se].pb(mp(p.fi, p.se.fi));
			}
		}
		cout << "Case #" << curt << endl; ++curt;
		for(int i = 0; i < q; ++i) {
			cin >> vq1 >> vq2;
			root = vq1; visited.fill(false); globallo = -1;
			dfs(vq1);
		}
	}
	return 0;
}
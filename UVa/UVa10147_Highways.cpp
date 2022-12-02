#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................
int p[756], renk[756];

int findSet(int u) {
	if(u != p[u]) {
		return p[u] = findSet(p[u]);
	} else return u;
}

bool isSameSet(int u, int v) {
	if(findSet(u) == findSet(v)) {
		return true;
	} else return false;
}

void UnionSet(int u, int v) {
	u = findSet(u);
	v = findSet(v);
	if(u != v) {
		if(renk[u] < renk[v]) swap(u, v);
		p[v] = u;
		if(renk[u] == renk[v]) renk[u]++;
	}
}

vector<pair<int, ii>> edgeList;
vector<ii> node;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	bool ft = true;
	while(T--) {
		if(ft) ft = false;
		else cout << endl;
		memset(renk, 0, sizeof(renk));
		edgeList.clear(); node.clear();
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i) p[i] = i;
		int x, y;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			node.pb({x, y});
		}
		for(int i = 0; i < n; ++i) {
			for(int j = i; j < n; ++j) {
				ll dist = ((node[i].fi - node[j].fi) * (node[i].fi - node[j].fi)) + ((node[i].se - node[j].se) * (node[i].se - node[j].se));
				edgeList.pb({dist, {i, j}});
			}
		}
		sort(all(edgeList));
		
		int m;
		cin >> m;
		int u, v;
		for(int i = 0; i < m; ++i) {
			cin >> u >> v;
			UnionSet(u - 1, v - 1);
		}
		
		vector<ii> edgeNeed;
		for(auto p : edgeList) {
			if(!isSameSet(p.se.fi, p.se.se)) {
				edgeNeed.pb({p.se.fi + 1, p.se.se + 1});
				UnionSet(p.se.fi, p.se.se);
			}
		}
		
		sort(all(edgeNeed));
		
		if(sza(edgeNeed) == 0) {
			cout << "No new highways need" << endl;
		} else {
			for(auto p : edgeNeed) {
				cout << p.fi << " " << p.se << endl;
			}
		}
	}
	return 0;
}
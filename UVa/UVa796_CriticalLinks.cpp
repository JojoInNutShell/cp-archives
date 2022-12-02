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
array<vector<int>, MAX_N> adjList;
array<bool, MAX_N> visited;
array<int, MAX_N> lo, disc, par;
vector<ii> ans;
int di;

void init() {
	for(auto& a : adjList) a.clear();
	ans.clear();
	visited.fill(false);
	lo.fill(-1);
	disc.fill(-1);
	par.fill(-1);
	di = 0;
}

void dfs(int u) {
	visited[u] = true;
	lo[u] = di; disc[u] = di; ++di;
	for(auto v : adjList[u]) {
		if(visited[v] == false) {
			par[v] = u;
			dfs(v);
			lo[u] = min(lo[v], lo[u]);
			if(disc[u] < lo[v]) {
				ans.pb(mp(min(v, u), max(v, u)));
			}
		} else if(v != par[u]) {
			lo[u] = min(disc[v], lo[u]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int v, adjnum, a, n;
	string sval, sn;
	while(cin >> n) {
		init();
		for(int i = 0; i < n; ++i) {
			cin >> v >> sval;
			sn.clear();
			for(auto c : sval) {
				if(c != '(' && c != ')') {
					sn.pb(c);
				}
			}
			adjnum = stoi(sn);
			for(int j = 0; j < adjnum; ++j) {
				cin >> a;
				adjList[v].pb(a);
			}
		}
		for(int i = 0; i < n; ++i) {
			if(visited[i] == false) dfs(i);
		}
		sort(ans.begin(), ans.end());
		cout << sza(ans) << " critical links" << endl;
		for(auto p : ans) {
			cout << p.fi << " - " << p.se << endl;
		}
		cout << endl;
	}
	
	return 0;
}
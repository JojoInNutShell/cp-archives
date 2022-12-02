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
//........................................................................
array<vector<int>, 206> adj;
array<bool, 206> visited;
array<short int, 206> color;
bool bicolorable;

void init() {
	adj.fill({});
	visited.fill(false);
	color.fill(0);
	bicolorable = true;
}

void dfs(int u, bool isOne) {
	visited[u] = true; int Ncol;
	if(isOne) {
		color[u] = 1;
		Ncol = 2;
	} else {
		color[u] = 2;
		Ncol = 1;
	}
	
	for(auto v : adj[u]) { //CHECK WARNA DI SEKITAR
		if(color[v] == 0) {
			continue;
		}
		if(color[v] != Ncol) {
			bicolorable = false;
		}	
	}
	
	for(auto v : adj[u]) { //CHECK WARNA DI SEKITAR
		if(visited[v] == false) {
			dfs(v, isOne ^ 1);
		}	
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, e, v1, v2;
	while(cin >> n >> e) {
		init();
		for(int i = 0; i < e; ++i) {
			cin >> v1 >> v2;
			adj[v1].pb(v2);
			adj[v2].pb(v1);
		}
		dfs(0, true);
		if(bicolorable) {
			cout << "BICOLORABLE.";
		} else {
			cout << "NOT BICOLORABLE.";
		} cout << endl;
	}
	
	
	return 0;
}
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
array<vi, 2006> adjList;
array<bool, 2006> visited, onSt;
vector<int> st;
array<int, 2006> lo, id;
int di, scc;

void init() {
	for(auto& a : adjList) a.clear();
	visited.fill(false);
	onSt.fill(false);
	st.clear();
	lo.fill(1);
	id.fill(1);
	di = 1; scc = 0;
}

void dfs(int u) {
	visited[u] = true;
	id[u] = di; lo[u] = di++;
	onSt[u] = true; st.pb(u);
	for(auto v : adjList[u]) {
		if(visited[v] == false) {
			dfs(v);
		}
		if(onSt[v]) {
			lo[u] = min(lo[v], lo[u]);
		}
	}
	if(id[u] == lo[u]) {
		++scc;
		while(1) {
			int v = st.back(); st.pop_back(); onSt[v] = false;
			if(u == v) break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, v1, v2, stype;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		init();
		for(int i = 0; i < m; ++i) {
			cin >> v1 >> v2 >> stype;
			adjList[v1].pb(v2);
			if(stype == 2) {
				adjList[v2].pb(v1);
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(visited[i] == false) dfs(i);
		}
		if(scc > 1) {
			cout << 0;
		} else {
			cout << 1;
		}
		cout << endl;
	}
	return 0;
}
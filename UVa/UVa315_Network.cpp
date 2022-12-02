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
int di, rootChild, root, totarc;
array<vector<int>, 106> adjList;
array<bool, 106> visited;
array<bool, 106> arc;
array<int, 106> lo;
array<int, 106> disc;
array<int, 106> par;

void init() {
	for(auto& a : adjList) a.clear();
	visited.fill(0);
	lo.fill(INF);
	disc.fill(INF);
	par.fill(-1);
	arc.fill(false);
	totarc = 0;
}

void dfs(int u) {
	visited[u] = true;
	disc[u] = di; lo[u] = di; ++di;
	for(auto v : adjList[u]) {
		if(visited[v] == false) {
			par[v] = u; if(u == root) rootChild++;
			dfs(v);
			lo[u] = min(lo[u], lo[v]);
			if(disc[u] <= lo[v]) {
				arc[u] = true;
			}
		} else if(v != par[u]) {
			lo[u] = min(lo[u], disc[v]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n;
	while(cin >> n) {
		init();
		if(n == 0) return 0;
		while(1) {
			string text_line;
		  	getline(cin, text_line);
		  	if(text_line == "0") break;
		  	istringstream input_stream(text_line);
		 	int val, c = 0, v;
		 	while (input_stream >> val) {
		 		if(c == 0) {
		 			v = val;
		 			++c;
		 			continue;
		 		}
		    	adjList[v].pb(val);
		    	adjList[val].pb(v);
		  	}
		}
		for(int i = 1; i <= n; ++i) {
			if(visited[i] == false) {
				root = i; rootChild = 0; di = 1;
				dfs(i);
				arc[i] = (rootChild > 1);
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(arc[i]) ++totarc;
		}
		
		cout << totarc << endl;
	}
	return 0;
}
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
map<int, string> numname;
map<string, int> namenum;
array<vi,50> adjList;
array<bool, 50> visited;
array<bool, 50> onSt;
vector<int> st;
array<int, 50> id, lo;
pair<int, string> pp;
int di, curdt;

void init() {
	numname.clear();
	namenum.clear();
	visited.fill(false);
	onSt.fill(false);
	for(auto& a : adjList) a.clear();
	st.clear();
	di = 0;
}

void dfs(int u) {
	visited[u] = true;
	st.pb(u); onSt[u] = true;
	id[u] = di; lo[u] = di++;
	for(auto v : adjList[u]) {
		if(visited[v] == false) {
			dfs(v);
		}
		if(onSt[v]) {
			lo[u] = min(lo[v], lo[u]);
		}
	}
	if(lo[u] == id[u]) {
		while(1) {
			int v = st.back(); st.pop_back(); onSt[v] = false;
			pp = *(numname.find(v));
			cout << pp.se;
			if(u == v) {
				cout << endl;
				break;
			}
			cout << ", ";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, pc;
	string v1, v2;
	pair<string, int> p1, p2;
	curdt = 1;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		init();
		pc = 0;
		for(int i = 0; i < m; ++i) {
			cin >> v1 >> v2;
			if(namenum.find(v1) == namenum.end()) {
				namenum.insert(mp(v1, pc));
				numname.insert(mp(pc++, v1));
			}
			if(namenum.find(v2) == namenum.end()) {
				namenum.insert(mp(v2, pc));
				numname.insert(mp(pc++, v2));
			}
			p1 = *(namenum.find(v1));
			p2 = *(namenum.find(v2));
			adjList[p1.se].pb(p2.se);
		}
		cout << "Calling circles for data set " << curdt << ":" << endl; ++curdt;
		for(int i = 0; i < n; ++i) {
			if(visited[i] == false) {
				dfs(i);
			}
		}
	}
	return 0;
}
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
array<vii, 1006> adjList;
priority_queue<pair<int, int>> pq;
array<bool, 1006> visited;

void init() {
	for(auto& a : adjList) a.clear();
	visited.fill(false);
}

void addEdges(int u) {
	visited[u] = true; 
	for(auto p : adjList[u]) {
		if(visited[p.se] == false) {
			pq.push(mp(-(p.fi), p.se));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, curt = 1;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) return 0; 
		else {
			if(curt != 1) cout << endl;
			++curt;
		}
		multiset<int> ans;
		init();
		int v1, v2, w;
		for(int i = 0; i < m; ++i) {
			cin >> v1 >> v2 >> w;
			adjList[v1].pb(mp(w, v2));
			adjList[v2].pb(mp(w, v1));
			ans.insert(w);
		}
		for(int i = 0; i < n; ++i) {
			if(visited[i] == false) {
				addEdges(i);
				while(!pq.empty()) {
					ii p = pq.top(); pq.pop();
					if(visited[p.se] == false) {
						addEdges(p.se);
						ans.erase(-(p.fi));
					}
				}
			}
		}
		if(sza(ans) == 0) {
			cout << "forest";
		} else {
			for(auto v : ans) {
				cout << v << " ";
			}
		}
		
	}	
	return 0;
}
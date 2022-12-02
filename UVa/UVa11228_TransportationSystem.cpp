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
priority_queue<pair<double, int>> pq;
array<vector<pair<double, int>>, 1006> adjList;
vector<pair<int, int>> nodeList;
array<bool, 1006> visited;

void init() {
	for(auto& a : adjList) a.clear();
	visited.fill(false);
	nodeList.clear();
}

double dist(double x1, double y1, double x2, double y2) {
	return sqrt(pow(abs(x1 - x2),2) + pow(abs(y1 - y2), 2));
}

void addEdges(int u) {
	for(auto p : adjList[u]) {
		if(visited[p.se] == false) {
			pq.push(mp(-(p.fi), p.se));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T, n, px, py;
	double r;
	cin >> T;
	for(int nt = 1; nt <= T; ++nt) {
		init();
		cin >> n >> r;
		for(int i = 0; i < n; ++i) {
			cin >> px >> py;
			nodeList.pb(mp(px, py));
		}
		double dis;
		for(int i = 0; i < sza(nodeList); ++i) {
			for(int j = i + 1; j < sza(nodeList); ++j) {
				dis = dist(nodeList[i].fi, nodeList[i].se, nodeList[j].fi, nodeList[j].se);
				adjList[i].pb(mp(dis, j));
				adjList[j].pb(mp(dis, i));
			}
		}
		addEdges(0);
		visited[0] = true;
		double road = 0, railroad = 0;
		int nstate = 0;
		while(!pq.empty()) {
			pair<double, int> p;
			p = pq.top(); pq.pop();
			if(visited[p.se] == false) {
				visited[p.se] = true;
				if(-(p.fi) >= r) {
					railroad += -(p.fi);
					++nstate;
				} else {
					road += -(p.fi);
				}
				addEdges(p.se);
			} else {
				continue;
			}
		}
		road = round(road); railroad = round(railroad);
		cout << "Case #" << nt << ": " << ++nstate << " " << road << " " << railroad << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

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
const ll INF = 2e9;
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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int curt = 1; curt <= T; ++curt) {
		int n, m, s, t;
		priority_queue<ii,vector<ii> , greater<ii>> pq;
		cin >> n >> m >> s >> t;
		
		array<vii, 20006> adjList;
		array<int, 20006> dist; dist.fill(INF);
		int v1, v2, w;
		for(int i = 0; i < m; ++i) {
			cin >> v1 >> v2 >> w;
			adjList[v1].pb(mp(w, v2));
			adjList[v2].pb(mp(w, v1));
		}
		pq.push(mp(0, s)); dist[s] = 0;
		while(!pq.empty()) {
			ii p = pq.top(); pq.pop();
			if(p.fi > dist[p.se]) continue;
			for(auto v : adjList[p.se]) {
				if(p.fi + v.fi < dist[v.se]) {
					dist[v.se] = p.fi + v.fi;
					pq.push(mp(dist[v.se], v.se));
				}
			}
		}
		cout << "Case #" << curt << ": ";
		if(dist[t] == INF) {
			cout << "unreachable" << endl;
		} else {
			cout << dist[t] << endl;
		}
	}
	return 0;
}
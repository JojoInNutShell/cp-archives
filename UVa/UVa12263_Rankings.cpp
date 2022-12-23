/*
	Author: MikiMiku
	
	Observation:
		1. The uncertainty situation (the using '?' situation) 
		is a trap. This is because if the data is
		uncertain then it must be incosistent,
		hence leading us to "IMPOSSIBLE" answer.
		
		2. We can see the rankings as a relation
		graph with nodes are the teams and there
		is an edge from team a to team b if team a's
		rank is higher than team b's rank.
		
	Idea: 
		By observation 2, we know that to recover
		the ranking, we could just do toposort on
		that graph. But, before that we need to
		do some change on the graph as there are 
		pairs given indicating relative change on 
		the ranking. For every pair given we just
		need to reverse the edge direction which
		connect the teams in the pair.
		
		After done with the change we will do
		toposort on the graph. It is "IMPOSSIBLE"
		to make the ranking list if and only if
		there is a cycle in that graph.
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
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
int adjMat[507][507], indeg[507];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	
	while(T--) {
		int n;
		cin >> n;
		vector<int> t(n);
		for(int i = 0; i < n; ++i) cin >> t[i];
		
		memset(adjMat, 0, sizeof(adjMat));
		
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				adjMat[t[i]][t[j]] = 1;
			}
		}
		
		int m;
		cin >> m;
		for(int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			swap(adjMat[a][b], adjMat[b][a]);
		}
		
		memset(indeg, 0, sizeof(indeg));
		
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 1; j <= n; ++j) {
				indeg[i] += adjMat[j][i];
				indeg[j] += adjMat[i][j];
			}
		}
		
		queue<int> q;
		for(int i = 1; i <= n; ++i) {
			if(indeg[i] == 0) q.push(i);
		}
		
		int c = 0;
		int r[507];
		while(!q.empty()) {
			int u = q.front(); q.pop();
			r[c++] = u;
			
			for(int i = 1; i <= n; ++i) {
				if(adjMat[u][i]) {
					if(--indeg[i] == 0) {
						q.push(i);
					}
				}
			}
		}
		
		if(c != n) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			for(int i = 0; i < n; ++i) {
				cout << r[i];
				if(i + 1 == n) cout << endl;
				else cout << " ";
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
map<int, map<int, vii>> adjList;
map<int, set<int>> valid;
map<ii, bool> visited;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int x0, y0, x1, y1, n;
	cin >> x0 >> y0 >> x1 >> y1;
	cin >> n;
	int r, ca, cb;
	for(int i = 0; i < n; ++i) {
		cin >> r >> ca >> cb;
		for(int j = ca; j <= cb; ++j) {
			valid[r].insert(j);
		}
	}
	for(auto p : valid) {
		r = p.fi;
		for(auto c : p.se) {
			if(valid[r - 1].find(c - 1) != valid[r - 1].end()) {
				adjList[r][c].pb({r - 1, c - 1});
			}
			if(valid[r - 1].find(c) != valid[r - 1].end()) {
				adjList[r][c].pb({r - 1, c});
			}
			if(valid[r - 1].find(c + 1) != valid[r - 1].end()) {
				adjList[r][c].pb({r - 1, c + 1});
			}
			if(valid[r].find(c + 1) != valid[r].end()) {
				adjList[r][c].pb({r, c + 1});
			}
			if(valid[r].find(c - 1) != valid[r].end()) {
				adjList[r][c].pb({r, c - 1});
			}
			if(valid[r + 1].find(c + 1) != valid[r + 1].end()) {
				adjList[r][c].pb({r + 1, c + 1});
			}
			if(valid[r + 1].find(c) != valid[r + 1].end()) {
				adjList[r][c].pb({r + 1, c});
			}
			if(valid[r + 1].find(c - 1) != valid[r + 1].end()) {
				adjList[r][c].pb({r + 1, c - 1});
			}
		}
	}
	/*
	for(auto mp1 : adjList) {
		for(auto mp2 : mp1.se) {
			cout << "r c" << endl;
			cout << mp1.fi << " " << mp2.fi << endl;
			cout << "adj : " << endl;
			for(auto p : mp2.se) {
				cout << p.fi << " " << p.se << endl;
			}
			cout << endl;
		}
	}
	*/
	queue<pair<int, pair<int, int>>> q;
	q.push({0,{x0, y0}}); visited[{x0, y0}] = true;
	int dist = -1;
	while(!q.empty()) {
		int di = q.front().fi;
		int curr = q.front().se.fi, curc = q.front().se.se;
		q.pop();
		//cout << curr << " " << curc << endl;
		if(curr == x1 && curc == y1) {
			dist = di;
			break;
		}
		for(auto p : adjList[curr][curc]) {
			//cout << p.fi << " " << p.se << endl;
			//cout << visited[{p.fi, p.se}] << endl;
			if(!visited[{p.fi, p.se}]) {
				visited[{p.fi, p.se}] = true;
				q.push({di + 1, {p.fi, p.se}});
			}
		}
	}
	cout << dist;
	return 0;
}
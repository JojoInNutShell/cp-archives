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
array<vector<int>, 100> adjList;
array<int, 100> deg;
array<bool, 100> visited;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int v1, v2;
	deg.fill(0); visited.fill(false);
	for(int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		adjList[v1].pb(v2);
		adjList[v2].pb(v1);
		deg[v1]++; deg[v2]++;
	}
	int nkick = 0;
	bool isKick;
	queue<int> q;
	while(1) {
		isKick = false;
		for(int i = 1; i <= n; ++i) {
			if(visited[i] == false && deg[i] == 1) {
				q.push(i);
				isKick = true;
				visited[i] = true;
			}
		}
		if(!isKick) {
			break;
		}
		nkick++;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(auto v : adjList[cur]) {
				deg[v]--;
			}
		}
	}
	cout << nkick;
	
	
	return 0;
}
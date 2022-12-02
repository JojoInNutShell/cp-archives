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
array<vector<int>, 2506> adjList;
array<bool, 2506> visited;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, f, T, qint;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> m;
		for(int j = 0; j < m; ++j) {
			cin >> f;
			adjList[i].pb(f);
		}
	}
	cin >> T;
	while(T--) {
		cin >> qint;
		if(adjList[qint].empty()) {
			cout << 0 << endl;
			continue;
		}
		queue<ii> q; vector<int> boom;
		boom.assign(66, 0);
		visited.fill(false);
		q.push(mp(qint, 0)); visited[qint] = true;
		while(!q.empty()) {
			ii p = q.front(); q.pop();
			for(auto v : adjList[p.fi]) {
				if(visited[v] == false) {
					boom[p.se + 1]++;
					visited[v] = true;
					q.push(mp(v,p.se + 1)); 
				}
			}
		}
		int high = -1, idx = 0;
		for(int i = 0; i < 66; ++i) {
			if(boom[i] > high) {
				high = boom[i];
				idx = i;
			}
		}
		cout << high << " " << idx << endl;
	}
	return 0;
}
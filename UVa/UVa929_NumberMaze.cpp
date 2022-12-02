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
array<array<int, 1006>, 1006> arr;
array<array<vector<pair<int, pair<int, int>>>, 1006>, 1006> adjList;
array<array<int, 1006>, 1006> dist;
int r, c;

void init() {
	for(auto& a : dist) a.fill(INF);
	for(auto& a : adjList) {
		for(auto& ar : a) {
			ar.clear();
		}
	}
}

bool isValid(int i, int j) {
	if(0 <= i && i < r && 0 <= j && j < c) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		init();
		cin >> r >> c;
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				cin >> arr[i][j];
			}
		}
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(isValid(i - 1, j)) {
					adjList[i][j].pb(mp(arr[i - 1][j],mp(i - 1, j)));
				}
				if(isValid(i + 1, j)) {
					adjList[i][j].pb(mp(arr[i + 1][j],mp(i + 1, j)));
				}
				if(isValid(i, j - 1)) {
					adjList[i][j].pb(mp(arr[i][j - 1],mp(i, j - 1)));
				}
				if(isValid(i, j + 1)) {
					adjList[i][j].pb(mp(arr[i][j + 1],mp(i, j + 1)));
				}
			}
		}
		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		pq.push(mp(arr[0][0], mp(0, 0))); dist[0][0] = arr[0][0];
		while(!pq.empty()) {
			pair<int, ii> p = pq.top(); pq.pop();
			for(auto pa : adjList[p.se.fi][p.se.se]) {
				if(p.fi > dist[pa.se.fi][p.se.se]) continue;
				if(p.fi + pa.fi < dist[pa.se.fi][pa.se.se]) {
					dist[pa.se.fi][pa.se.se] = p.fi + pa.fi;
					pq.push(mp(dist[pa.se.fi][pa.se.se], mp(pa.se.fi, pa.se.se)));
				}
			}
		}
		cout << dist[r - 1][c - 1] << endl;
	}
	return 0;
}
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
array<vector<int>, 107> adjList;
vector<int> ans;
bitset<107> cur, visited;

int n, m;

void backtrack(int u) {
	if(u > n) {
		vector<int> tmp;
		for(int i = 1; i <= n; ++i) {
			if(cur[i]) tmp.pb(i);
		}
		if(sza(tmp) > sza(ans)) {
			ans = tmp;
		}
		return;
	} else {
		bool can = true;
		for(auto i : adjList[u]) {
			if(cur[i]) {
				can = false;
				break;
			}
		}
		
		//visited[u] = true;
		if(can) {
			cur[u] = true;
			backtrack(u + 1);
		}
		cur[u] = false;
		backtrack(u + 1);
		//visited[u] = false;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	
	while(T--) {
		for(auto& a : adjList) a.clear();
		ans.clear();
		
		cin >> n >> m;
		
		for(int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adjList[u].eb(v);
			adjList[v].eb(u);
		}
		
		cur.reset(); visited.reset();
		backtrack(1);
		
		cout << sza(ans) << endl;
		for(int i = 0; i < sza(ans); ++i) {
			cout << ans[i];
			if(i + 1 != sza(ans)) cout << " ";
		} cout << endl;
	}
	return 0;
}
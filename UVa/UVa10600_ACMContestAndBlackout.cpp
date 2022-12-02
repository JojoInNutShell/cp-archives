#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
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
int p[106], renk[106];

int findSet(int u) {
	if(u != p[u]) {
		return p[u] = findSet(p[u]);
	} else return u;
}

bool isSameSet(int u, int v) {
	if(findSet(u) == findSet(v)) {
		return true;
	} else return false;
}

void unionSet(int u, int v) {
	u = findSet(u);
	v = findSet(v);
	if(u != v) {
		if(renk[u] < renk[v]) swap(u, v);
		p[v] = u;
		if(renk[u] == renk[v]) renk[u]++;
	}
}

bool check(int n) {
	p[1] = findSet(p[1]);
	for(int i = 2; i <= n; ++i) {
		p[i] = findSet(p[i]);
		if(p[1] != p[i]) return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	//bool ft = true;
	while(T--) {
		
		int n, m;
		cin >> n >> m;
		int u, v, c;
		vector<pair<int, ii>> edgeList;
		for(int i = 0; i < m; ++i) {
			cin >> u >> v >> c;
			edgeList.pb({c, {u, v}});
		}
		
		//vector<ii> edgeUsed;
		vector<int> idUsed;
		int cost1 = 0, cost2 = INF;
		int cnt = 0;
		
		memset(renk, 0, sizeof(renk));
		for(int i = 1; i <= n; ++i) p[i] = i;
		sort(all(edgeList));
		
		for(auto p : edgeList) {
			if(!isSameSet(p.se.fi, p.se.se)) {
				cost1 += p.fi;
				unionSet(p.se.fi, p.se.se);
				idUsed.pb(cnt);
			}
			cnt++;
		}
		
		for(auto i : idUsed) {
			memset(renk, 0, sizeof(renk));
			for(int k = 1; k <= n; ++k) p[k] = k;
			int tmp = 0;
			for(int j = 0; j < sza(edgeList); ++j) {
				if(i == j) continue;
				if(!isSameSet(edgeList[j].se.fi, edgeList[j].se.se)) {
					tmp += edgeList[j].fi;
					unionSet(edgeList[j].se.fi, edgeList[j].se.se);
				} 
			}
			if(check(n)) {
				cost2 = min(tmp, cost2);
			}
		}
		cout << cost1 << " " << cost2 << endl;
	}
	return 0;
}
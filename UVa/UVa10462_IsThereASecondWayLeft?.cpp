/*
	Author: MikiMiku
	
	Idea: 
		This is a Minimum Spanning Tree Variant Task.
		To know the second best MST all we could do is
		is to try to make a MST (If we can't do that
		then the answer must be "No way"). Then for
		every edge that is in the most MST, we try
		to make another MST without using that
		edge. After that, from all possible second
		most MST take the best of them 
		(Don't forget that it needs to be a tree). 
		If there is no possible second best MST, then
		our answer must be "No second way". Else,
		we print the second best MST.
		
		In this implementation, it will be easier
		using kurskal MST algorithm than prim ones.
		Also, to check if the current possible MST
		is connected, just check if all of the
		nodes are in the same set (Or same parent).
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
int p[107], renk[107];

int findSet(int u) {
	if(u != p[u]) return p[u] = findSet(p[u]);
	else return u;
}

int isSameSet(int u, int v) {
	return findSet(u) == findSet(v);
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cout << "Case #" << tc << " : ";
		
		int n, m;
		cin >> n >> m;
		
		vector<pair<int, ii>> edgeList;
		for(int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edgeList.pb({w, {u, v}});
		}
		sort(all(edgeList));
		
		for(int i = 1; i <= n; ++i) p[i] = i;
		for(int i = 1; i <= n; ++i) renk[i] = 0;
		
		vector<int> ansid;
		for(int i = 0; i < m; ++i) {
			int u = edgeList[i].se.fi, v = edgeList[i].se.se;
			if(!isSameSet(u, v)) {
				ansid.pb(i);
				unionSet(u,v);
			}
		}
		
		bool ok = true;
		for(int i = 1; i <= n; ++i) {
			findSet(i);
			if(i > 1 && p[i] != p[i - 1]) {
				cout << "No way" << endl;
				ok = false;
				break;
			}
		}
		
		if(!ok) continue;
		
		int ans = INF;
		for(int k = 0; k < sza(ansid); ++k) {
			int ban = ansid[k];
			
			for(int i = 1; i <= n; ++i) p[i] = i;
			for(int i = 1; i <= n; ++i) renk[i] = 0;
			
			int res = 0;
			for(int i = 0; i < m; ++i) {
				if(i == ban) continue;
				
				int u = edgeList[i].se.fi, v = edgeList[i].se.se;
				if(!isSameSet(u, v)) {
					res += edgeList[i].fi;
					unionSet(u, v);
				}
			}
			
			bool valid = true;
			for(int i = 1; i <= n; ++i) {
				findSet(i);
				if(i > 1 && p[i] != p[i - 1]) {
					valid = false;
					break;
				}
			}
			
			if(valid) ans = min(ans, res);
		}
		
		if(ans != INF) {
			cout << ans << endl;
		} else {
			cout << "No second way" << endl;
		}
	}
	return 0;
}
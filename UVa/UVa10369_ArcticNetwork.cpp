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
int renk[506], p[506];

int findSet(int u) {
	if(u != p[u]) {
		return p[u] = findSet(p[u]);
	} else return u;
}

bool isSameSet(int u, int v) {
	if(findSet(u) == findSet(v)) return true;
	else return false;
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

vector<pair<double, ii>> edgeList;
vector<pair<double, double>> P;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		edgeList.clear();
		P.clear();
		int s, n;
		cin >> s >> n; s--;
		double x, y;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			P.pb({x, y});
		}
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				edgeList.pb({hypot(P[i].fi - P[j].fi, P[i].se - P[j].se), {i, j}});
			}
		}
		sort(all(edgeList));
		
		vector<pair<double, ii>> usedEdge;
		
		memset(renk, 0, sizeof(renk));
		for(int i = 0; i < n; ++i) p[i] = i;
		
		for(auto p : edgeList) {
			if(!isSameSet(p.se.fi, p.se.se)) {
				unionSet(p.se.fi, p.se.se);
				usedEdge.pb(p);
			}
		}
		
		int bk = sza(usedEdge) - 1;
		double ans = (s < 0 ? usedEdge[bk].fi : usedEdge[bk - s].fi);
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << ans << endl;
	}
	return 0;
}
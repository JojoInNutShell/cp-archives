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
//........................................................................
vi renk, p;

vector<ii> edgeList;

int findset(int u) {
	if(u == p[u]) return u;
	else {
		return p[u] = findset(p[u]);
	}
}

bool isSameSet(int u, int v) {
	if(findset(u) == findset(v)) return true;
	else return false;
}

void unionSet(int u, int v) {
	u = findset(u);
	v = findset(v);
	if(u != v) {
		if(renk[u] < renk[v]) swap(u, v);
		p[v] = u;
		if(renk[u] == renk[v]) renk[u]++;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	renk.assign(n, 0); p.clear();
	for(int i = 0; i < n; ++i) p.pb(i);
	vector<ii> closeEdges;
	int u, v;
	for(int i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		if(isSameSet(u - 1, v - 1)) {
			//cerr << u << " " << v << endl;
			closeEdges.pb({u, v});
		} else {
			unionSet(u - 1, v - 1);
		}
		/*
		for(auto val : p) {
			cerr << val << " ";
		} cerr << endl;
		*/
	}
	
	vector<int> iso;
	for(int i = 0; i < n; ++i) {
		if(p[i] == i) {
			//cerr << i << endl;
			iso.pb(i + 1);
		}
	}
	vector<ii> newRoad; 
	for(int i = 1; i < sza(iso); ++i) {
		newRoad.pb({iso[0], iso[i]});
	} 
	int sz = sza(newRoad);
	cout << sz << endl;
	for(int i = 0; i < sz; ++i) {
		cout << closeEdges[i].fi << " " << closeEdges[i].se << " " << newRoad[i].fi << " " << newRoad[i].se << endl;
	}
	
	return 0;
}
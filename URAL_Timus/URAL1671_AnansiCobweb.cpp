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

int findset(int u) {
	if(u == p[u]) return u;
	else return p[u] = findset(p[u]);
}

int isSameSet(int u, int v) {
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
	int n, m;
	cin >> n >> m;
	renk.assign(n, 0);
	for(int i =0; i < n; ++i) p.pb(i);
	
	vector<ii> edgeList(m + 1);
	set<ii> setupList;
	stack<ii> destroyList;
	for(int i = 1; i <= m; ++i) {
		cin >> edgeList[i].fi >> edgeList[i].se;
		setupList.insert({edgeList[i].fi, edgeList[i].se});
	}
	int nq;
	cin >> nq;
	int didx;
	for(int i = 0; i < nq; ++i) {
		cin >> didx;
		//cerr << edgeList[didx].fi << " " << edgeList[didx].se << endl;
		destroyList.push({edgeList[didx].fi, edgeList[didx].se});
		setupList.erase({edgeList[didx].fi, edgeList[didx].se});
	}
	//SETUP
	for(auto p : setupList) {
		unionSet(p.fi - 1, p.se - 1);
	}
	int nCom = 0;
	for(int i = 0; i < n; ++i) {
		if(p[i] == i) nCom++;
	}
	vector<int> ans;
	while(!destroyList.empty()) {
		ii e = destroyList.top(); destroyList.pop();
		ans.pb(nCom);
		if(!isSameSet(e.fi - 1, e.se - 1)) {
			nCom--;
			unionSet(e.fi - 1, e.se - 1);
		}
	}
	reverse(all(ans));
	for(auto val : ans) {
		cout << val <<  " ";
	}
	return 0;
}
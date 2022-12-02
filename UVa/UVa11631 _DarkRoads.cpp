#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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
class UnionFind {
	private : vi p, rank;
	public :
	UnionFind(int N) {
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; ++i) {
			p[i] = i;
		}
	}
	int findset(int u) {
		if(p[u] == u) {
			return u;
		} else {
			p[u] = findset(p[u]);
			return p[u];
		}
	}
	bool isSameSet(int i, int j) {
		return findset(i) == findset(j);
	}
	void UnionSet(int i, int j) {
		int x = findset(i); int y = findset(j);
		if(rank[x] > rank[y]) {
			p[y] = x; 
		} else {
			p[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
};

multimap<int, pair<int, int>> edgeList;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	while(cin >> n >> m) {
		if(n == 0 && m == 0) break;
		UnionFind UF(n); edgeList.clear();
		int x, y, z;
		for(int i = 0; i < m; ++i) {
			cin >> x >> y >> z;
			edgeList.insert(mp(z, mp(x, y)));
		}
		int maxsave = 0;
		for(auto p : edgeList) {
			if(!UF.isSameSet(p.se.fi, p.se.se)) {
				UF.UnionSet(p.se.fi, p.se.se);
			} else {
				maxsave += p.fi;
			}
		}
		cout << maxsave << endl;
	}
	return 0;
}
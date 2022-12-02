#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int n;
array<array<int, 17>, 17> memo;
array<array<vector<ii>, 17>, 17> memov;
ll m[17];

ll dp(int l, int r) {
	if(memo[l][r] != -1) return memo[l][r];
	
	ll res = INF;
	if(r - l == 1) {
		memov[l][r].pb({l, r});
		res = m[l] * m[r] * m[r + 1];
		return memo[l][r] = res;
	} else if(l == r) {
		res = 0;
		return memo[l][r] = res;
	}
	
	for(int i = l; i < r; ++i) {
		int cur = (m[l] * m[i + 1] * m[r + 1]) + dp(l, i) + dp(i + 1, r);
		if(cur < res) {
			res = cur;
			memov[l][r].clear();
			for(auto p : memov[l][i]) memov[l][r].pb(p);
			for(auto p : memov[i + 1][r]) memov[l][r].pb(p);
			memov[l][r].pb({l, r});
		}
	}
	return memo[l][r] = res;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	
	int tc = 1;
	while(cin >> n) {
		if(n == 0) break;
		
		for(int i = 0; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			m[i] = u;
			if(i == n - 1) m[n] = v;
		}
		
		for(auto& arr : memo) arr.fill(-1);
		for(auto& arr : memov) {
			for(auto& ar : arr) ar.clear();
		}
		
		dp(0, n - 1);
		//cerr << memo[0][n - 1] << endl;
		
		ii br[17];
		memset(br, 0, sizeof(br));
		for(auto p : memov[0][n - 1]) {
			//cerr << p.fi << " " << p.se << endl;
			br[p.fi].fi++;
			br[p.se].se++;
		}
		
		cout << "Case " << tc++ << ": ";
		for(int i = 0; i < n; ++i) {
			if(i) {
				cout << " x ";
			}
			
			for(int j = 0; j < br[i].fi; ++j) {
				cout << "(";
			}
			cout << "A" << (i + 1);
			for(int j = 0; j < br[i].se; ++j) {
				cout << ")";
			}
		} cout << endl;
	}
	return 0;
}
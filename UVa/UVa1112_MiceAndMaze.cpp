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
array<vector<pair<ll, ll>>, 106> adjList;
array<ll, 106> dist;

void init() {
	for(auto& a : adjList) a.clear();
	//dist.fill(INF);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll n,e,t,m, T;
	bool ft = true;
	cin >> T;
	while(T--) {
		if(!ft) cout << endl;
		else ft = false;
		init();
		cin >> n >> e >> t >> m;
		ll a, b, w;
		for(ll i = 0; i < m; ++i) {
			cin >> a >> b >> w;
			adjList[a].pb(mp(w, b));
		}
		array<ll, 106> dist; ll mousecnt = 0;
		for(ll s = 1; s <= n; ++s) {
			priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
			dist.fill(INF);
			pq.push(mp(0,s)); dist[s] = 0;
		 	while(!pq.empty()) {
		 		pair<ll,ll> p = pq.top(); pq.pop();
		 		for(auto pa : adjList[p.se]) {
		 			if(p.fi > dist[pa.se]) continue;
		 			if(p.fi + pa.fi < dist[pa.se]) {
		 				dist[pa.se] = p.fi + pa.fi;
		 				pq.push(mp(dist[pa.se], pa.se));
		 			}
		 		} 
		 	}
		 	if(dist[e] <= t) {
		 		mousecnt++;
		 	}
		}
		cout << mousecnt;
		if(T != 0) cout << endl;  
	}
	return 0;
}
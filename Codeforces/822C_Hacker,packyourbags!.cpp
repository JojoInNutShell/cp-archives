/*
	Author: MikiMiku
	
	Idea: 
		If we have voucher with duration d, then
		we need another voucher with duration x - d.
		We could just find the lowest voucher cost
		with duration x - d, but the next problem
		is not just to find the lowest cost but
		also to find voucher which days don't
		intersect.
		
		In this implementation to find the 
		voucher which have cost x - d. We
		will save it in a map the voucher with
		that cost. To find the non-intersecting
		voucher we will save the L and R
		section of vouchers with such cost
		then sort it to make it binary search-able.
		To find the lowest voucher cost just make
		a prefix/suffix minimum array. 
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
const ll INF = 1e10;
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	
	vector<pair<ii, int>> dat(n);
	for(int i = 0; i < n; ++i) cin >> dat[i].fi.fi >> dat[i].fi.se >> dat[i].se;
	
	map<int, vector<pair<ii, int>>> miv;
	for(int i = 0; i < n; ++i) {
		int day = dat[i].fi.se - dat[i].fi.fi + 1;
		miv[day].pb(dat[i]);
	}
	
	map<int, vector<ii>> Ldat, Rdat;
	map<int, vector<int>> sufL, preR;
	for(auto v : miv) {
		int sz = sza(v.se);
		for(auto p : v.se) {
			Ldat[v.fi].pb({p.fi.fi, p.se});
			Rdat[v.fi].pb({p.fi.se, p.se});
		}
		sort(all(Ldat[v.fi]));
		sort(all(Rdat[v.fi]));
		
		vector<ii>& L(Ldat[v.fi]), R(Rdat[v.fi]);
		
		sufL[v.fi].assign(sz, 0);
		preR[v.fi].assign(sz, 0);
		
		sufL[v.fi][sz - 1] = L[sz - 1].se;
		for(int i = sz - 2; i >= 0; --i) {
			sufL[v.fi][i] = min(sufL[v.fi][i + 1], L[i].se);
		}
		
		preR[v.fi][0] = R[0].se;
		for(int i = 1; i < sz; ++i) {
			preR[v.fi][i] = min(preR[v.fi][i - 1], R[i].se);
		}
		
	}
	
	ll ans = INF;
	for(int i = 0; i < n; ++i) {
		int l = dat[i].fi.fi, r = dat[i].fi.se;
		int day = r - l + 1;
		int need = x - day;
		if(!miv.count(need)) continue;
		int sz = sza(miv[need]);
		
		pair<ll, ll> p1 = {l - 1, 1e9}, p2 = {r + 1, -1};
		auto itpre = upper_bound(Rdat[need].begin(), Rdat[need].end(), p1);
		if(itpre != Rdat[need].begin()) itpre--;
		auto itsuf = lower_bound(Ldat[need].begin(), Ldat[need].end(), p2);
		
		int idR = itpre - Rdat[need].begin();
		int idL = itsuf - Ldat[need].begin();
		
		ll add = INF;
		if(idR < sz && Rdat[need][idR].fi < l) {
			add = min(add, preR[need][idR]);
		}
		if(idL < sz && r < Ldat[need][idL].fi) {
			add = min(add, sufL[need][idL]);
		}
		
		ans = min(ans, add + dat[i].se);
	}
	
	if(ans == INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
	
	return 0;
}
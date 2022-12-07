/*
	Author: MikiMiku
	
	Observation:
		1. Cause no two circles (target) may overlap.
		Then the shot may at most hit two circles.
		
		Let's say that the shot hit three target (more than two).
		Then the target must be overlapping at some
		place (or it's impossible to set three
		different circles (fulfiling the task requirement)
		so that given any point. The point will
		be inside all the three circles.)
		
		2. Hitting two circle may only be possible,
		when different circle border touching each other
		and the shot hit it's touching border.
		
	Idea:
		By using observation 1, then we may
		sort the circles (target) based on it's
		x-axis first and do binary search 
		(also based on it's x-axis) on the
		shot. As the shot may only be fall
		between at most two it's nearest target.
		
		After that, all we need to do is just
		to check if the shot, hit the target.
		Which can be done easily using hypot()
		c++ STL function, but because we're working
		with int/long long we will just ceil it up.
		It's fine because the target radius is
		in integer.
		
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	
	vector<pair<ll, ll>> xr(n);
	map<pair<ll, ll>, int> id;
	for(int i = 0; i < n; ++i) cin >> xr[i].fi >> xr[i].se, id[xr[i]] = i;
	sort(all(xr));
	
	vector<int> hit(n, -1);
	
	int m;
	int c = 0;
	
	cin >> m;
	for(int i = 0; i < m; ++i) {
		ll x, y;
		cin >> x >> y;
		auto it = lower_bound(all(xr), mp(x, 0ll));
		if(it == xr.begin()) {
			pair<ll, ll> p1 = *it;
			if(ceil(hypot(x - p1.fi, y)) <= p1.se) {
				int pos = id[p1];
				if(hit[pos] == -1) hit[pos] = i + 1, c++;
			}
		} else if(it == xr.end()) {
			pair<ll, ll> p1 = *(prev(it));
			if(ceil(hypot(x - p1.fi, y)) <= p1.se) {
				int pos = id[p1];
				if(hit[pos] == -1) hit[pos] = i + 1, c++;
			}
		} else {
			pair<ll, ll> p1 = *it;
			pair<ll, ll> p2 = *(prev(it));
			
			int pos1 = id[p1], pos2 = id[p2];
			
			if(ceil(hypot(x - p1.fi, y)) <= p1.se) {
				if(hit[pos1] == -1) hit[pos1] = i + 1, c++;
			}
			if(ceil(hypot(x - p2.fi, y)) <= p2.se) {
				if(hit[pos2] == -1) hit[pos2] = i + 1, c++;
			}
		}
	}
	
	cout << c << endl;
	for(int i = 0; i < n; ++i) {
		cout << hit[i] << " ";
	} cout << endl;
	return 0;
}
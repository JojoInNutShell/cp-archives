/*
	Author: MikiMiku
	
	Observation:
		1. We can do some cycle before having
		empty paint
		2. Empty paint don't allow us to do
		any cycle
		
	Idea: 
		When the problem comes into
		observation 2 state than we know
		the answer should just be the longest
		sequence not containing zeros, and we
		may come to that state by observation 1
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
const ll INF = 1e15;
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
	
	vector<ll> a(n); ll mn = INF;
	vector<ll> zpos;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	
	
	for(int i = 0; i < n; ++i) {
		a[i] -= mn;
		if(a[i] == 0) zpos.pb(i);
	}
	
	ll ans = 0;
	for(int i = 0; i < sza(zpos); ++i) {
		ll l = i, r = (i + 1) % sza(zpos);
		l = zpos[l], r = zpos[r];
		ll c = 0;
		for(int j = (l + 1)%n; j != r; ++j, j%=n) {
			c++;
		}
		ans = max(ans, c);
	}
	
	ans += (mn*n);
	cout << ans << endl;
	return 0;
}
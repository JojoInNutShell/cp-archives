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
 
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll n, sum;
	cin >> n >> sum;
	
	vector<ll> d(n);
	
	ll tot = 0;
	for(int i = 0; i < n; ++i) cin >> d[i], tot += d[i];
	
	ll mn = (n - 1);
	for(int i = 0; i < n; ++i) {
		if(i) cout << " ";
		ll l = 1, r = d[i];
		while(l < r) {
			ll mid = (l + r + 1) >> 1;
			ll sisa = sum - mid;
			if(sisa >= mn) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		ll posr = l;
		
		l = 1, r = d[i];
		ll mx = tot - d[i]; 
		while(l < r) {
			ll mid = (l + r) >> 1;
			ll sisa = sum - mid;
			if(sisa <= mx) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		ll posl = l;
		
		//cerr << d[i] << " " << posl << " " << posr << endl;
		
		cout << d[i] - (posr - posl + 1);
	} cout << endl;
	
	return 0;
}
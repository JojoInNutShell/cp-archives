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
//........................................................................

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll x, a, d, n;
	cin >> x >> a >> d >> n;
	if(d < 0) {
		ll fi;
		fi = a + d*(n - 1);
		a = fi;
		d *= -1;
	}
	ll l = 1, r = n + 1;
	while(l < r) {
		ll mid = (l + r)/2;
		ll num = (a + (mid - 1)*d);
		if(x > num) {
			l = mid + 1;
		} else if(x < num) {
			r = mid;
		} else {
			cout << 0;
			exit(0);
		}
	}
	ll ans;
	if(l == 1) {
		ans = a - x;
		cout << ans;
	} else if(l == n + 1) {
		ans = x - (a + (l - 2)*d);
		cout << ans;
	} else {
		ll num = (a + (l - 1)*d);
		ans = min(num - x, x - (num - d));
		cout << ans;
	}
	return 0;
}
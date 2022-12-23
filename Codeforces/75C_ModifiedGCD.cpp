/*
	Author: MikiMiku
	
	Idea: 
		We store all possible divisor of the greatest
		common divisor of a and b, sort it. Then do binary search
		on it, if there is a range of answer, return
		the largest one. Else return -1.
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
	int a, b;
	cin >> a >> b;
	
	int gc = __gcd(a, b);
	
	vector<ll> d;
	for(ll i = 1; i*i <= gc; ++i) {
		if(gc%i == 0) {
			d.pb(i);
			if(gc/i != i) d.pb(gc/i);
		}
	} sort(all(d));
	
	int sz = sza(d);
	
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		
		auto itl = lower_bound(d.begin(), d.end(), l);
		auto itr = lower_bound(d.begin(), d.end(), r);
		
		int dl = itl - d.begin();
		int dr = itr - d.begin();
		
		if(dr == sz || d[dr] > r) dr--;
		
		if(dr < dl) {
			cout << -1 << endl;
		} else {
			cout << d[dr] << endl;
		}
	}
	return 0;
}
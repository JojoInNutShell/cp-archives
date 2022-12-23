/*
	Author: MikiMiku
	
	Observation:
		1. If a and b was the score of a possible game 
		then we could represent a and b as follows
		
		p^2 * q   = a 
		p   * q^2 = b
		(for some integer p and q)
		
		Note that,
		
		a*b = p^3 * q^3
		
		Which means,
		
		cbrt(a*b) = p*q  (cbrt() is a cubic root function)
		
		Then, if a and b was really in that p and
		q form. We could test it if cbrt(a*b) divides a
		and cbrt(a*b) divides b, but don't forget
		that a*b must be a perfect cubic root.
		
	Idea: 
		In this implementation we use binary search
		to search for the cubic root. It has been
		tried using the STL cbrt() function
		but leads to WA. (I don't know why exactly
		that happen, but I think it's also safer
		if we just dealing with integer, not float or double)
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

ll crt(ll n) {
	ll l = 0, r = 1e6;
	while(l < r) {
		ll mid = (l + r + 1)/2;
		ll res = mid*mid*mid;
		if(res > n) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	return l;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		ll a, b;
		cin >> a >> b;
		
		ll ab = a*b;
		ll cb = crt(ab);
		ll cb3 = cb*cb*cb;
		
		if(cb3 == ab && a%cb == 0 && b%cb == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
 		}
	}
	return 0;
}
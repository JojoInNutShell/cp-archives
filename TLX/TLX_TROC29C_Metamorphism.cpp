/*
	Author: MikiMiku
	
	Observation:
		1. We need to know that we may get another
		free operation by,
		
		(i, j, k) starting point
		(i + 1, j + 1, k - 1) cost 0
		(i + 1 + 1, j + 1 - 1, k - 1 + 1) cost 0
		(i + 2, j, k) cost 0
		
		We can add (or minus(by the same idea))
		every element by two.
		
	Idea: 
		Firstly, let us define another
		triplet which is how much we difference
		from the first triplet to the second triplet
		or (a - d, b - e, c - f). Notice that,
		Observation 1 still applies on this triplet.
		
		So, when all elements on the triplet
		are even, then no fish is needed. If
		all elements on the triplet are odd.
		We could use any one of the free fish 
		operation, changing all the elements to even.
		So, in this case also 0 fish needed.
		
		But other than that case (When the parity
		of all elements are not the same). We
		need 1 fish.
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
	ll a, b, c, d, e, f;
	cin >> a >> b >> c;
	cin >> d >> e >> f;
	
	ll x = abs(a - d), y = abs(b - e), z = abs(c - f);
	if(((x%2==0) && (y%2==0) && (z%2==0)) || ((x%2 == 1) && (y%2 == 1) && (z%2 == 1))) {
		cout << 0 << endl;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
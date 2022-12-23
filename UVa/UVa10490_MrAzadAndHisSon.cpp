/*
	Author: MikiMiku
	
	Idea: 
		Just do as ask, but it's known that
		k must be prime (necessary but not sufficient) 
		for the formula to produce a perfect number.
		
		For the implementation as k is small inaf
		we just list all primes and all perfect numbers
		available up to that. Just look at OEIS.
		
		But just watch out when k = 31. The result
		of the formula is a bit too much even
		for unsigned long long so add it as a
		corner case.
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
	set<ull> primes({2,3,5,7,11,13,17,19,23,29,31});
	set<ull> perfect({6, 28, 496, 8128, 33550336, 8589869056, 137438691328});
	ull k;
	while(cin >> k) {
		if(k == 0) break;
		if(k == 31) {
			cout << "Perfect: 2305843008139952128!" << endl;
			continue;
		}
		ull res = (1ll << (k - 1))*((1ll << k) - 1);
		if(perfect.count(res)) {
			cout << "Perfect: " << res << "!" << endl;
		} else if(primes.count(k)) {
			cout << "Given number is prime. But, NO perfect number is available." << endl;
		} else {
			cout << "Given number is NOT prime! NO perfect number is available." << endl;
		}
	}
	
	return 0;
}
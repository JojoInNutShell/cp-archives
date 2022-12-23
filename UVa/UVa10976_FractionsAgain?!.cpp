/*
	Author: MikiMiku
	
	Definition:
		Follow the definition that was stated in
		the task.
	
	Observation:
		1. We know that 1/k = 2/(2*k) = ... = m/(m*k)
		for any integer m.
		
	Idea:
		We will construct our answer based
		on observation 1. That means let's
		we have k = 12. Then,
		
		1/12 = 7/(7*12)
		1/12 = 7/84
		
		1/12 = 1/84 + 6/84 -> 1/12 = 1/84 + 1/14
		1/12 = 2/84 + 5/84 -> We can't simplify more, leading to invalid combination
		1/12 = 3/84 + 4/84 -> 1/12 = 1/28 + 1/21
		
		We can't always gurantee that all the
		pairs generated will produce valid
		answer, also trying to brute force
		all possible pairs doesn't seem to be
		a feasible thing to do as it is unclear
		when we need to stop and at least need O(k*k)
		complexity, yet to include test case which
		lead to O(t*k*k) (where t is equal to
		the number of test cases) which surely lead
		this type of solution to TLE.
		
		But, see that when we are trying to brute force
		
		1/12 = i/12*m + j/12*m for all possible integer i, j where i + j = m. 
		
		To make i/12*m to be able to simplify. We
		need i divides 12, i divides m or a divisor
		of i divides 12 and the rest divides m or 
		vice versa. But when working with m, 
		m is not a constant which hard to work
		around with.
		
		So rather than working around on m. How
		about we work on the 12 (or k). Then we
		need i and j to divides 12. Which, of course
		the only possible i, j is where i and j
		is the divisor of 12 (or k).
		
		This way will much reduce the complexity
		until O(t*sqrt(k)).
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
	
	int k;
	while(cin >> k) {
		vector<int> d;
		for(int i = 1; i*i <= k; ++i) {
			if(k%i == 0) {
				d.pb(i);
				if(i != (k/i)) {
					d.pb((k/i));
				}
			}
		}
		sort(all(d));
		
		set<ii, greater<ii>> ans;
		int sz = sza(d);
		for(int i = 0; i < sz; ++i) {
			for(int j = i; j < sz; ++j) {
				int m = d[i] + d[j];
				int km = k*m;
				
				int gcdi = __gcd(d[i], km);
				int gcdj = __gcd(d[j], km);
				
				if(gcdi == d[i] && gcdj == d[j]) {
					ans.emplace(km/gcdi, km/gcdj);
				}
			}
		}
		
		cout << sza(ans) << endl;
		for(auto p : ans) {
			cout << "1/" << k << " = " << "1/" << p.fi << " + " << "1/" << p.se << endl; 
		}
	}
	return 0;
}
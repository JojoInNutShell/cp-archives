/*
	Author: MikiMiku
	
	Hint:
		1. What is the maximum answer that could
		we get by using the flipping operation
		optimally?
	
	Observation:
		let's define n as the length of the given
		string.
		
		1. When the current longest alternating
		subsequence is n - 1, there must be "00"
		or "11" substring. But,when the the current
		longest alternating subsequence is n - 2,
		there must be "00" and "11" substring.
		2. Flipping "00...11" (not including first
		0 and lat 1) will always increase the
		longest alternating subsequence by 2.
		
	Idea:
		By observation 2, then the answer must
		be min(n, longest current alternating subsequence + 2). 
		
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
	string s;
	cin >> s;
	
	vector<int> subseq({s[0]});
	for(int i = 1; i < n; ++i) {
		if(subseq.back() != s[i]) {
			subseq.pb(s[i]);
		}
	}
	
	ll ans = min(n, sza(subseq) + 2);
	cout << ans << endl;
	return 0;
}
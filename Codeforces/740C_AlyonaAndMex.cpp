/*
	Author: MikiMiku
	
	Observation:
		1. The maximum possible minimum mex must be
		less than the smallest subarray.
		
		It's obvious that with subarray length len.
		Then, the answer will be less than or equal
		to len.
		
	Idea:
		By observation 1, we can extend this further
		by stating that we can gurantee
		that the maximum possible minimum mex will
		be equal to the size of smallest subarray (say len)
		by arranging the array this way,
		0, 1, 2, ..., len - 1, 0, 1, 2, ..., len - 1, ...
		
		That way it will be guranteed that the maximum
		possible minimum mex will be equal to the
		size of smallest subarray.
		
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
	int n, m;
	cin >> n >> m;
	
	int len = INF;
	for(int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		len = min(len, r - l + 1);
	}
	
	vector<int> ans(n);
	for(int i = 0; i < n; ++i) {
		ans[i] = i%len;
	}
	
	cout << len << endl;
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;
	return 0;
}
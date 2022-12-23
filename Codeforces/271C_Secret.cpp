/*
	Author: MikiMiku
	
	Observation:
		1. There is no solution to the case where
		n/k < 3 because now it's inevitable to
		have arithmetic progression in some set U
		that set will contain only 1 or 2 elements
		which must made an arithmetic progression.
		
		We need at least 3 elements in a set U
		to break the arithmetic progression.
	
	Idea: 
		We want to gurantee breaking the arithmetic
		progression for every set U. To accomplish this
		we could make a pattern like this,
		
		(n = 9, k = 3)
		1 1 2 2 3 3 1 2 3
		
		Or generally,
		
		i i i+1 i+1 i+2 i+2 ... i i+1 i+2
		
		The idea is that to break the arithmetic
		progression we make the first difference
		equal to 1 but the next difference 
		is not equal to 1.
		
		If there is more space left 
		(or the current pattern made is still less than n)
		just fill the gap with 1
		as it's already guranteed that the
		arithmetic progression will break.
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
	int n, k;
	cin >> n >> k;
	
	if(n/k < 3) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<int> u(n);
	int c = 1;
	for(int i = 0; i < n - k; i += 2) {
		u[i] = c;
		u[i + 1] = c;
		c++;
	}
	c = 1;
	for(int i = n - k; i < n; ++i) {
		u[i] = c;
		c++;
	}
	
	for(int i = 0; i < n; ++i) {
		if(u[i] > k) {
			cout << 1 << " ";
		} else {
			cout << u[i] << " ";
		}
	}
	return 0;
}
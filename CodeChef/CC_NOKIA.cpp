#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int dpmin[50], dpmax[50];

int fmax(int n) {
	if(dpmax[n] != 0) return dpmax[n];
	if(n == 1) {
		return dpmax[n] = 1;
	} else {
		return dpmax[n] = n + 1 + fmax(n - 1);
	}
}

int fmin(int n) {
	if(dpmin[n] != 0) return dpmin[n];
	if(n == 1) {
		return dpmin[n] = 1;
	} else {
		return dpmin[n] = n + fmin((n + 1)/2) + fmin(n/2);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	memset(dpmin, 0, sizeof(dpmin));
	memset(dpmax, 0, sizeof(dpmax));
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		int mn = fmin(n + 1) - (n + 1);
		int mx = fmax(n + 1) - (n + 1);
		if(m < mn) {
			cout << -1;
		} else if(mn <= m && m <= mx) {
			cout << 0;
		} else {
			cout << m - mx;
		}
		cout << endl;
	}
	return 0;
}
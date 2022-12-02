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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................

class MergersDivTwo {
	double dp[57];
	public:
	double findMaximum(vector<int> revenues, int k) {
		int n = sza(revenues);
		sort(all(revenues));
		vector<double> a(n + 1);
		for(int i = 1; i <= n; ++i) a[i] = revenues[i - 1];
		
		vector<double> pre(n + 1, 0);
		for(int i = 1; i <= n; ++i) pre[i] = pre[i - 1] + a[i];
		
		for(int i = 0; i < n; ++i) dp[i] = pre[i + 1]/(double)(i + 1);
		for(int i = 0; i < (k - 1); ++i) dp[i] = -INF;
		
		for(int i = 0; i < n; ++i) {
			for(int j = i - (k - 1); j >= (k - 1); --j) {
				double cur = (dp[j] + pre[i + 1] - pre[j + 1])/(double)(i - j + 1);
				dp[i] = max(dp[i], cur);
			}
		}
		
		return dp[n - 1];
	}
};

/*
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	vector<int> tmp;
	int kt;
	int m;
	cin >> m >> kt;
	for(int i = 0; i < m; ++i) {
		int t; cin >> t;
		tmp.pb(t);
	}
	MergersDivTwo MD;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(13);
	cout << MD.findMaximum(tmp, kt);
	return 0;
}
*/
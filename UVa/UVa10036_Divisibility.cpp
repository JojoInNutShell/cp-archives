#include <bits/stdc++.h>
using namespace std;

#define int long long
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
bool dp[10007][107];

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; ++i) cin >> a[i];
		
		memset(dp, 0, sizeof(dp));
		int ak = (a[0] % k);
		if(ak < 0) ak += k;
		dp[0][ak] = 1;
		
		for(int i = 1; i < n; ++i) {
			for(int j = 0; j < 101; ++j) {
				int curl = j - a[i];
				curl %= k;
				if(curl < 0) curl += k;
				int curr = j + a[i];
				curr %= k;
				if(curr < 0) curr += k;
				
				dp[i][j] |= dp[i - 1][curl] | dp[i - 1][curr];
			}	
		}
		
		// for(int i = 0; i < n; ++i) {
			// for(int j = 0; j < k; ++j) {
				// cerr << dp[i][j] << " ";
			// } cerr << endl;
		// }
		
		if(dp[n - 1][0]) {
			cout << "Divisible";
		} else {
			cout << "Not divisible";
		} cout << endl;
	}
	return 0;
}
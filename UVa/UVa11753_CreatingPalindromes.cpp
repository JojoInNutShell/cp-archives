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
map<pair<ii, int>, int> memo;
int a[10007];

int dp(int i, int j, int k) {
	if(memo.count({{i, j}, k})) return memo[{{i, j}, k}];
	
	ll res = 0;
	
	if(k > 20) {
		res = k;
		memo[{{i, j}, k}] = res;
		return k;
	}
	
	if(j - i <= 1) {
		if(a[i] == a[j]) {
			res = k;
			memo[{{i, j},k}] = res;
		}
		else {
			res = k + 1;
			memo[{{i, j}, k}] = res;
		}
	} else {
		if(a[i] == a[j]) {
			res = dp(i + 1, j - 1, k);
			memo[{{i, j}, k}] = res;
		} else {
			res = min(dp(i + 1, j, k + 1), dp(i, j - 1, k + 1));
			memo[{{i, j}, k}] = res;
		} 
	}
	
	return res;
}

bool palin(int i, int j) {
	if(j - i <= 1) return a[i] == a[j];
	
	if(a[i] == a[j]) return palin(i + 1, j - 1);
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cout << "Case " << tc << ": ";
		
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; ++i) cin >> a[i];
		
		memo.clear();
		
		if(palin(0, n - 1)) {
			cout << "Too easy" << endl;
			continue;
		}
		
		ll ans = dp(0, n - 1, 0);
		if(ans > k) {
			cout << "Too difficult" << endl;
		} else cout << ans << endl;
	}
	return 0;
}
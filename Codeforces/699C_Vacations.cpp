#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
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
array<array<bool, 106>, 106> blist;
array<array<int, 106>, 106> memo;

int dp(int n) {
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(j == 0) memo[i][j] = memo[i - 1][j] + 1;
			if(j == 1) {
				if(blist[i][j]) {
					memo[i][j] = min(memo[i - 1][j - 1], min(memo[i - 1][j] + 1, memo[i - 1][j + 1]));
				} else {
					memo[i][j] = min(memo[i - 1][j - 1], min(memo[i - 1][j], memo[i - 1][j + 1])) + 1;
				}
			}
			if(j == 2) {
				if(blist[i][j]) {
					memo[i][j] = min(memo[i - 1][j - 2], min(memo[i - 1][j - 1], memo[i - 1][j] + 1));
				} else {
					memo[i][j] = min(memo[i - 1][j - 2], min(memo[i - 1][j - 1], memo[i - 1][j])) + 1;
				}
			}
		}
	}
	return min(memo[n][0], min(memo[n][1], memo[n][2]));
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, t;
	cin >> n;
	for(auto& a : memo) a.fill(0);
	for(auto& a : blist) a.fill(false);
	for(int i = 1; i <= n; ++i) {
		cin >> t;
		blist[i][0] = true;
		if(t == 0) continue;
		if(t == 3) {
			blist[i][1] = true;
			blist[i][2] = true;
		} else {
			blist[i][t] = true;
		}
	}
	cout << dp(n);
	return 0;
}
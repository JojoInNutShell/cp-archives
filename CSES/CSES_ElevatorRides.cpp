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
//........................................................................
array<array<vector<vector<int>>, 26>, 26> memoa;
int memo[26][26];
int n, mxw;
vector<int> arr;

int dp(int i, int l) {
	if(memo[i][l] != 0) return memo[i][l];
	else {
		if(i == n) {
			return memo[i][l] = l;
		} else {
			if(i == 0) {
				memoa[i + 1][l + 1].pb({arr[i]});
				return dp(i + 1, 1);
			} else {
				if(memoa[i][l].empty()) {
					return memo[i][l] = INF;
				}
				for(auto& v : memoa[i][l]) {
					for(auto& e : v) {
						if(e + arr[i] <= mxw) {
							e += arr[i];
							memoa[i + 1][l].pb(v);
							e -= arr[i];
						}
					}
					v.pb(arr[i]);
					memoa[i + 1][l + 1].pb(v);
					v.pop_back();
				}
				return min(dp(i + 1, l), dp(i + 1, l + 1));
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> mxw;
	arr.assign(n, 0);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	memset(memo, 0, sizeof(memo));
	cout << dp(0, 0);
	//for(int i = 1; i <= n)
	return 0;
}
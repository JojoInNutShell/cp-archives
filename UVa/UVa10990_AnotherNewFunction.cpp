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
bitset<2000006> bs;
//vector<int> primes;
array<int, 2000006> dp, preSum;
ll SieveSize;

void sieve(int u) {
	SieveSize = u + 1;
	bs.set();
	bs[0] = bs[1] = false;
	for(int i = 2; i <= SieveSize; ++i) {
		dp[i] = i;
	}
	for(int i = 2; i <= SieveSize; ++i) {
		if(bs[i]) {
			for(int j = 2*i; j <= SieveSize; j += i) {
				bs[j] = false;
				dp[j] -= dp[j]/i;
			}
			dp[i] = i - 1;
			//primes.pb(i);
		}
	}
}

/*
int phi(int n) {
	int idx = 0, PF = primes[idx], ans = n;
	while(PF*PF <= n) {
		if(n % PF == 0) ans -= ans/PF;
		while(n % PF == 0) n /= PF;
		PF = primes[++idx];
	}
	if(n != 1) ans -= ans/n;
	return ans;
}
*/

void precomdp(int u) {
	dp[2] = 1; preSum[2] = 1; preSum[1] = 0;
	for(int i = 3; i <= u; ++i) {
		dp[i] = dp[dp[i]] + 1;
		preSum[i] = preSum[i - 1] + dp[i];
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(2000000);
	precomdp(2000001);
	int T;
	cin >> T;
	int l, r;
	while(T--) {
		cin >> l >> r;
		cout << preSum[r] - preSum[l - 1] << endl;
	}
	return 0;
}
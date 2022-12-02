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
//........................................................................
int tab[16][16];
vector<int> tx({0,0,1,1,1,-1,-1,-1}), ty({1,-1,1,0,-1,1,0-1});

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		for(int j = 0; j < n; ++j) {
			tab[i][j] = s[j] - '0';
		}
	}
	ll mx = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < 8; ++k) {
				int ti = i, tj = j;
				ll ans = 0;
				for(int m = 0; m < n; ++m) {
					ans *= 10;
					ans += tab[ti][tj];
					ti += tx[k]; tj += ty[k];
					ti %= n; tj %= n;
					if(ti < 0) ti = n + ti;
					if(tj < 0) tj = n + tj;
				}
				mx = max(mx, ans);
			}
		}
	}
	cout << mx;
	return 0;
}
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
int h[3], w[3];
int ans;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];
	int mx = 0;
	for(int i = 0; i < 3; ++i) {
		mx = max(mx, h[i]);
		mx = max(mx, w[i]);
	}
	ans = 0;
	int arr[3][3];
	for(int i = 1; i <= mx; ++i) {
		for(int j = 1; j <= mx; ++j) {
			for(int k = 1; k <= mx; ++k) {
				for(int m = 1; m <= mx; ++m) {
					arr[0][0] = i;
					arr[0][1] = j;
					arr[1][0] = k;
					arr[1][1] = m;
					arr[0][2] = h[0] - arr[0][0] - arr[0][1];
					if(arr[0][2] <= 0) continue;
					arr[2][0] = w[0] - arr[0][0] - arr[1][0];
					if(arr[2][0] <= 0) continue;
					arr[1][2] = h[1] - arr[1][0] - arr[1][1];
					if(arr[1][2] <= 0) continue;
					arr[2][1] = w[1] - arr[0][1] - arr[1][1];
					if(arr[2][1] <= 0) continue;
					if(h[2] - arr[2][0] - arr[2][1] != w[2] - arr[0][2] - arr[1][2]) continue;
					arr[2][2] = h[2] - arr[2][0] - arr[2][1];
					if(arr[2][2] <= 0) continue;
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
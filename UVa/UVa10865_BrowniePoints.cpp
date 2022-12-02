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
array<ii, 200000> arr;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		int x2, y2;
		ii mid;
		for(int i = 0; i < n; ++i) {
			cin >> x2 >> y2;
			arr[i] = {x2, y2};
			if(i == n / 2) mid = arr[i];
		}
		int s = 0, o = 0;
		int x1 = mid.fi, y1 = mid.se;
		for(int i = 0; i < n; ++i) {
			if(i == n/2) continue;
			x2 = arr[i].fi; y2 = arr[i].se;
			if(x1 == x2 || y1 == y2) {
				continue;
			} else if(x2 > x1 && y2 > y1) {
				s++;
			} else if(x2 < x1 && y2 > y1) {
				o++;
			} else if(x2 < x1 && y2 < y1) {
				s++;
			} else {
				o++;
			}
		}
		cout << s << " " << o << endl;
	}
	
	return 0;
}
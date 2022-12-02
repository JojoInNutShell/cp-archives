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
vector<int> harr, curarr;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	bool ft = true;
	while(cin >> n) {
		if(n == 0) break;
		//if(ft) ft = false;
		//else cout << endl;
		int hsum = 0, cursum = 0, h = -1e17;
		harr.clear(); curarr.clear();
		int t;
		for(int i = 0; i < n; ++i) {
			cin >> t;
			if(t == 0) continue;
			if(t > h) h = t;
			cursum += t;
			curarr.pb(t);
			if(cursum < 0) {
				curarr.clear();
				cursum = 0;
			}
			if(cursum > hsum) {
				hsum = cursum;
				harr.clear();
				copy(curarr.begin(), curarr.end(), back_inserter(harr));
			}
			if(cursum == hsum) {
				if(sza(curarr) < sza(harr)) {
					harr.clear();
					copy(curarr.begin(), curarr.end(), back_inserter(harr));
				}
			}
		}
		if(sza(harr) == 0) {
			if(h == -1e17) h = 0;
			harr.pb(h);
		}
		int sz = sza(harr);
		for(int i = 0; i < sz; ++i) {
			cout << harr[i];
			if(i + 1 != sz) cout << " ";
		}
		cout << endl;
	}
	return 0;
}
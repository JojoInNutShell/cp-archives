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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, x;
	cin >> n >> x;
	if(n < 4) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<int> arr(n);
	for(int i = 0; i < n; ++i) cin >> arr[i];
	multimap<int, pair<int,int>> dsp;
	/*
	for(int i = 1; i < n - 2; ++i) {
		cerr << "DSP : " << i << endl;
		for(auto p : dsp[i]) {
			cerr << p.fi << " " << p.se.fi << " " << p.se.se << endl;
		}
		cerr << endl;
	}
	*/
	bool found = false;
	for(int i = 1; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			int m = x - arr[i] - arr[j];
			if(dsp.count(m)) {
				found = true;
				auto pos = dsp.find(m);
				cout << (*pos).se.fi << " " << (*pos).se.se << " " << i + 1 << " " << j + 1;
				break;
			}
		}
		if(found) break;
		for(int k = 0; k < i; ++k) {
			dsp.insert({arr[k] + arr[i], {k + 1, i + 1}});
		}
	}
	if(!found) {
		cout << "IMPOSSIBLE";
	}
	return 0;
}
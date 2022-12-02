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
	int T;
	cin >> T;
	while(T--) {
		int n, w;
		cin >> n >> w;
		int h = (w + 1)/2;
		vector<ii> arr;
		int t;
		for(int i = 0; i < n; ++i) {
			cin >> t;
			if(t > w) continue;
			arr.pb({t, i + 1});
		}
		int sz = sza(arr);
		bool found = false; int id;
		for(int i = 0; i < sz; ++i) {
			if(h <= arr[i].fi) {
				id = arr[i].se;
				found = true;
				break;
			} 
		}
		if(found) {
			cout << 1 << endl;
			cout << id << endl;
			continue;
		}
		int sum = 0;
		vector<int> ans;
		for(int i = 0; i < sz; ++i) {
			sum += arr[i].fi;
			ans.pb(arr[i].se);
			if(h <= sum) {
				break;
			}
		}
		if(h <= sum) {
			cout << sza(ans) << endl;
			for(auto v : ans) {
				cout << v << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
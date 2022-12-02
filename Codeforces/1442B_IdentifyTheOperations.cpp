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
const ll MOD = 998244353;
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
		int n, k;
		cin >> n >> k;
		list<int> a;
		vector<int> b;
		set<int> bc;
		int t;
		for(int i = 0; i < n; ++i) cin >> t, a.pb(t);
		unordered_map<int, list<int>::iterator> itol;
		for(auto it = a.begin(); it != a.end(); ++it) itol[*it] = it;
		for(int i = 0; i < k; ++i) cin >> t, b.pb(t), bc.insert(t);
		int ans = 1;
		list<int>::iterator pl, pr;
		bool fpl, fpr;
		for(auto it : b) {
			auto pos = itol[it];
			if(sza(a) == 1) {
				ans *= 0;
				break;
			} else if(pos == a.begin()) {
				pr = (next(a.begin()));
				if(bc.find(*(pr)) == bc.end()) {
					ans *= 1;
					a.erase(pr);
				} else {
					ans *= 0;
					break;
				}
			} else if(pos == prev(a.end())) {
				pl = (prev(prev(a.end())));
				if(bc.find(*pl) == bc.end()) {
					ans *= 1;
					a.erase(pl);
				} else {
					ans *= 0;
					break;
				}
			} else {
				pl = (prev(pos));
				pr = (next(pos));
				fpl = bc.find(*pl) != bc.end();
				fpr = bc.find(*pr) != bc.end();
				if(!fpl && !fpr) {
					ans *= 2;
					a.erase(pl);
				} else if(!fpl) {
					ans *= 1;
					a.erase(pl);
				} else if(!fpr) {
					ans *= 1;
					a.erase(pr);
				} else {
					ans *= 0;
					break;
				}
			}
			*pos = n + 1;
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
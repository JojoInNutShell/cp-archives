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
	vector<int> a1, a2;
	int t;
	for(int i = 0; i < n/2; ++i) {
		cin >> t;
		a1.pb(t);
	}
	for(int i = n/2; i < n; ++i) {
		cin >> t;
		a2.pb(t);
	}
	vector<pair<int, pair<int, int>>> s1, s2;
	
	int sz1 = sza(a1);
	for(int i = 0; i < sz1; ++i) {
		for(int j = i + 1; j < sz1; ++j) {
			s1.pb({a1[i] + a1[j], {i + 1, j + 1}});
		}
	}
	int sz2 = sza(a2);
	for(int i = 0; i < sz2; ++i) {
		for(int j = i + 1; j < sz2; ++j) {
			s2.pb({a2[i] + a2[j], {i + 1 + sz1, j + 1 + sz1}});
		}
	}
	sort(all(s1));
	sort(all(s2));
	/*
	for(auto p : s1) {
		cerr << p.fi << " " << p.se.fi << " " << p.se.se << endl;
	}
	cerr << endl;
	for(auto p : s2) {
		cerr << p.fi << " " << p.se.fi << " " << p.se.se << endl;
	}
	*/
	bool found = false;
	for(auto p : s1) {
		if(p.fi > x) break;
		pair<int, pair<int, int>> pf = {x - p.fi, {-INF, -INF}};
		auto pos = lower_bound(all(s2), pf);
		auto po = lower_bound(all(s1), pf);
		cerr << x - p.fi << endl;
		cerr << (*po).fi << " " << (*po).se.fi << " " << (*po).se.se << endl;
		if(pos != s2.end() && (*pos).fi == x - p.fi) {
			cout << p.se.fi << " " << p.se.se << " " << (*pos).se.fi << " " << (*pos).se.se;
			found = true;
			break;
		}
		if(po != s1.end() && (*po).fi == x - p.fi && p.se.fi != (*po).se.fi && p.se.se != (*po).se.se) {
			cout << p.se.fi << " " << p.se.se << " " << (*po).se.fi << " " << (*po).se.se;
			found = true;
			break;
		}
	}
	if(!found) {
		cout << "IMPOSSIBLE";
	}
	return 0;
}
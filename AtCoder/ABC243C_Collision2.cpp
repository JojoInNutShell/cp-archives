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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	vector<pair<pair<int, int>, char>> pa(n);
	for(int i = 0; i < n; ++i) {
		cin >> pa[i].fi.fi >> pa[i].fi.se;
	}
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i) {
		pa[i].se = s[i];
	}
	map<int, vector<pair<int, char>>> mip;
	for(int i = 0; i < n; ++i) {
		mip[pa[i].fi.se].pb({pa[i].fi.fi, pa[i].se});
	}
	for(auto& a : mip) {
		sort(a.se.begin(), a.se.end());
		for(auto it = next(a.se.begin()); it != a.se.end(); ++it) {
			char bf, af;
			bf = (*prev(it)).se;
			af = (*it).se;
			if(bf == 'R' && af == 'L') {
				cout << "Yes";
				exit(0);
			}
		}
	}
	cout << "No";
	
	return 0;
}
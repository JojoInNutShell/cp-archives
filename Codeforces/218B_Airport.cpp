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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m;
	cin >> n >> m;
	map<int, int> a;
	for(int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		a[tmp]++;
	}
	
	map<int, int> amx(a);
	int cmx = 0;
	for(int i = 0; i < n; ++i) {
		int mx = (*(prev(amx.end()))).fi;
		cmx += mx;
		amx[mx]--;
		if(amx[mx] == 0) amx.erase(mx);
		if(mx - 1 > 0) amx[mx - 1]++;
	}
	
	map<int, int> amn(a);
	int cmn = 0;
	for(int i = 0; i < n; ++i) {
		int mn = (*(amn.begin())).fi;
		cmn += mn;
		amn[mn]--;
		if(amn[mn] == 0) amn.erase(mn);
		if(mn - 1 > 0) amn[mn - 1]++;
	}
	
	cout << cmx << " " << cmn << endl;
	return 0;
}
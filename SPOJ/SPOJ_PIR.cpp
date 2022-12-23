/*
	Author: MikiMiku

	Idea: 
		Just implement the formula :)
		
		https://keisan.casio.com/exec/system/1329962711
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
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
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(4);
	
	int T;
	cin >> T;
	while(T--) {
		double a1, a2, a3, a4, a5, a6;
		cin >> a4 >> a6 >> a1 >> a5 >> a2 >> a3;
		
		a1 *= a1;
		a2 *= a2;
		a3 *= a3;
		a4 *= a4;
		a5 *= a5;
		a6 *= a6;
		
		double ans = 
		(1.0/144.0)*(a1*a5*(a2 + a3 + a4 + a6 - a1 - a5) 
		+ a2*a6*(a1 + a3 + a4 + a5 - a2 - a6) 
		+ a3*a4*(a1 + a2 + a5 + a6 - a3 - a4) 
		- a1*a2*a4 - a2*a3*a5 - a1*a3*a6 - a4*a5*a6);
		
		ans = sqrt(ans);
		cout << ans << endl;
	}
	return 0;
}
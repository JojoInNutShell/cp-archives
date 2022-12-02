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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(11);
	
	int nr1;
	double r1 = -1, tr1;
	cin >> nr1;
	for(int i = 0; i < nr1; ++i) {
		cin >> tr1;
		r1 = max(r1, tr1);
	}
	
	vector<double> ap1;
	int np1;
	double tp1;
	cin >> np1;
	for(int i = 0; i < np1; ++i) {
		cin >> tp1;
		ap1.pb(tp1);
	}
	
	int np2;
	double p2 = INF, tp2;
	cin >> np2;
	for(int i = 0; i < np2; ++i) {
		cin >> tp2;
		p2 = min(p2, tp2);
	}
	
	double a,b;
	cin >> a >> b;
	double res = -1;
	for(auto p1 : ap1) {
		//cout << r1*sqrt((b*p1) / (b*p1 + a*p2)) << endl;
		res = max(res, r1*sqrt((b*p1) / (b*p1 + a*p2)));
	}
	cout << res;
	return 0;
}
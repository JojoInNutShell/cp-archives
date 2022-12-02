#include <bits/stdc++.h>
using namespace std;

#define int long long
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

int gcd(int a, int b) {
	if(a < b) swap(a, b);
	if(b == 0) return a;
	return gcd(b, a % b);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int qu, qb;
	while(cin >> qu >> qb) {
		if(qu == 1 && qb == 1) break;
		string ans = "";
		int lu = 0, lb = 1, mu = 0, mb = 0, ru = 1, rb = 0;
		while(true) {
			mu = lu + ru;
			mb = lb + rb;
			//cerr << mu << " " << mb << endl;
			/*
			int kpkb = (mb/gcd(mb, qb))*qb;
			if(mu*(kpkb/mb) == qu*(kpkb/qb)) {
				break;
			} else if(mu*(kpkb/mb) < qu*(kpkb/qb)) {
				ans += 'R';
				lu = mu;
				lb = mb;
			} else {
				ans += 'L';
				ru = mu;
				rb = mb;
			}
			*/
			double e = (double)mu/(double)mb;
			double f = (double)qu/(double)qb;
			//cerr << e << " " << f;
			if(e == f) {
				//cerr << "break!" << endl;
				break;
			} else if(e < f) {
				ans += 'R';
				lu = mu;
				lb = mb;
			} else {
				ans += 'L';
				ru = mu;
				rb = mb;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
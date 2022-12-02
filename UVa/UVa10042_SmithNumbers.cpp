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
vector<int> p;
array<bool, 100006> isP;

void genprime(int n) {
	int sq = sqrt(n);
	for(auto& b : isP) b = true; 
	isP[0] = false; isP[1] = false;
	for(int i = 2; i < sq; ++i) {
		if(isP[i] == false) continue;
		for(int j = 2; i*j <= n; ++j) {
			isP[i*j] = false;
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(isP[i]) p.pb(i);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	genprime(100000);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		n++;
		while(1) {
			int digsum = 0; string tempn = to_string(n);
			for(auto ch : tempn) digsum += (ch - '0');
			int pdigsum = 0;
			vector<int>::iterator c = p.begin(); int divc = 0;
			string temp; int intn = n;
			while(intn > 1 && c != p.end()) {
				if((*c) > sqrt(intn)) {
					temp = to_string(intn);
					//cerr << intn << " " << (*c) << endl;
					for(auto ch : temp) pdigsum += (ch - '0');
					intn = 1;
					divc++;
				}
				if(intn % (*c) == 0) {
					temp = to_string((*c));
					//cerr << intn << " " << (*c) << endl;
					for(auto ch : temp) pdigsum += (ch - '0');
					intn /= (*c);
					divc++;
				} else c++;
			}
			if(divc > 1 && pdigsum == digsum) {
				cout << n << endl;
				break;
			} else {
				n++;
			}
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T, strsz;
	float ssz;
	string instr, s, s1, s2, s3;
	cin >> T;
	getline(cin, instr);
	for(int l = 1; l <= T; ++l) {
		getline(cin, instr);
		s.clear(); s1.clear(); s2.clear(); s3.clear();
		for(auto c : instr) {
			if(97 <= c && c <= 122) {
				s.pb(c);
			}
		}
		ssz = sza(s);
		if(floor(sqrt(ssz)) * floor(sqrt(ssz)) == ssz) { //Bentuk kuadrat
			strsz = sqrt(ssz);
		} else {
			cout << "Case #" << l << ":" << endl << "No magic :(" << endl;
			continue;
		}
		for(int i = 0; i < strsz; ++i) {
			for(int j = 0; j < strsz; ++j) {
				s1.pb(s[i + (j*strsz)]);
			}
		}
		for(int i = sza(s) - 1; i >= 0; --i) {
			s2.pb(s[i]);
		}
		for(int i = strsz - 1; i >= 0; --i) {
			for(int j = strsz - 1; j >= 0; --j) {
				s3.pb(s[i + (j*strsz)]);
			}
		}
		if(s == s1 && s1 == s2 && s2 == s3) {
			cout << "Case #" << l << ":" << endl << strsz << endl;
		} else {
			cout << "Case #" << l << ":" << endl << "No magic :(" << endl;
		}
	}
	return 0;
}
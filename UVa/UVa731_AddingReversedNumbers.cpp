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
string adds(vector<int>& as1, vector<int>& as2) {
	int sz1 = sza(as1), sz2 = sza(as2), p;
	string res;
	if(sz1 < sz2) {
		for(int i = 0; i < sz1; ++i) {
			as2[i] += as1[i];
			p = i;
			while(as2[p] > 9) {
				if(p == sz2 - 1) {
					as2.pb(1);
					as2[p] %= 10;
					break;
				}
				as2[p + 1] += 1;
				as2[p] %= 10;
				++p;
			}
		}
		for(auto i : as2) {
			res.pb(i + '0');
		}
	} else {
		for(int i = 0; i < sz2; ++i) {
			as1[i] += as2[i];
			p = i;
			while(as1[p] > 9) {
				if(p == sz1 - 1) {
					as1.pb(1);
					as1[p] %= 10;
					break;
				}
				as1[p + 1] += 1;
				as1[p] %= 10;
				++p;
			}
		}
		for(auto i : as1) {
			res.pb(i + '0');
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string s1, s2, res;
		vector<int> as1, as2;
		cin >> s1 >> s2;
		while(s1.back() == '0') s1.pop_back();
		while(s2.back() == '0') s2.pop_back();
		for(int i = 0; i < sza(s1); ++i) {
			as1.pb(s1[i] - '0');
		}
		for(int i = 0; i < sza(s2); ++i) {
			as2.pb(s2[i] - '0');
		}
		res = adds(as1, as2);
		while(res.front() == '0') {
			res.erase(0, 1);
		}
		cout << res << endl;
	}
	return 0;
}
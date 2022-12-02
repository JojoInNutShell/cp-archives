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

class MessageMess {
	ll memo[56];
	unordered_set<string> uss;
	string s, ans;
	
	ll dp(ll i) {
		if(memo[i] != -1) return memo[i];
		string cur;
		for(int j = 0; j <= i; ++j) cur += s[j];
		
		ll res = 0;
		for(int j = i; j >= 1; --j) {
			string ch;
			for(int k = j; k <= i; ++k) ch += s[k];
			if(uss.count(ch)) {
				ll pre = dp(j - 1);
				if(pre) {
					if(sza(ans) != 0) ans += ' ';
					ans += ch;
				}
				res += pre;
			}
		}
		if(uss.count(cur)) {
			res += 1;
			ans += cur;
		}
		return memo[i] = res;
	}
	public:
	string restore(vector<string> dictionary, string message) {
		memset(memo, -1, sizeof(memo));
		int sz = sza(dictionary);
		for(int i = 0; i < sz; ++i) uss.insert(dictionary[i]);

		s = message;
		int szm = sza(message);
		dp(szm - 1);
		
		if(memo[szm - 1] == 1) {
			return ans;
		} else if(memo[szm - 1] == 0) {
			return "IMPOSSIBLE!";
		} else {
			return "AMBIGUOUS!";
		}
	}
};

// signed main() {
	// ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	// vector<string> vs({"IMPOSS", "SIBLE", "S", "IMPOSSIBLE"});
	// string s = "IMPOSSIBLE";
	// MessageMess MS;
	// cout << MS.restore(vs, s) << endl;
	// return 0;
// }
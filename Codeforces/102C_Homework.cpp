/*
	Author: MikiMiku
	
	Idea: 
		List every distinct character in the string
		and save their amount. We must be greedy here.
		Deleting the lowest count character, if possible
		is our best move here.
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
	string s;
	int k;
	cin >> s >> k;
	
	int hash[26];
	memset(hash, 0, sizeof(hash));
	for(auto c : s) {
		hash[c - 'a']++;
		
	}
	
	vector<pair<int, char>> v;
	set<char> chs;
	for(int i = 0; i < 26; ++i) {
		if(hash[i] != 0) {
			v.pb({hash[i], 'a' + i});
			chs.insert('a' + i);
		}
	}
	sort(all(v));
	
	for(auto p : v) {
		if(p.fi <= k) {
			k -= p.fi;
			chs.erase(p.se);
		} else break;
	}
	
	string ans;
	for(auto c : s) {
		if(chs.count(c)) {
			ans += c;
		}
	}
	
	cout << sza(chs) << endl;
	cout << ans << endl;
	return 0;
}
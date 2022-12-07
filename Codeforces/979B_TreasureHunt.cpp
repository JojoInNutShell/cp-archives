/*
	Author: MikiMiku
	
	Hint:
		1. Think about cases when n == 1
		
	Observation:
		1. The beauty of the ribbon is determined
		by how much same subribbon (or substring)
		is there in the ribbon (string). But see
		that a character maybe a subribbon with
		smallest length.
		
	Idea:
		By observation 1, this means that we may be
		greedy on having as many as same
		characters as possible in the string.
		
		Hence, we just need to change the
		different character to the current
		most character in the ribbon. 
		
		But watchout on the case where the ribbon
		already contain the same character in it.
		
		Also the idea is that when we have more
		round than it need to change all characters
		in string to be same, the idea is just
		to delay it by changing it to another
		character different from the current
		most character. (But still watchout
		on the watchout said above)
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
	int n;
	cin >> n;
	
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	int sz = sza(s1);
	
	vector<pair<int, string>> mx;
	int hash[258];
	
	memset(hash, 0, sizeof(hash));
	
	int curmx = 0;
	for(auto c : s1) {
		hash[c]++;
		curmx = max(curmx, hash[c]);
	} 
	if(curmx == sz && n == 1) curmx--;
	else curmx = min(curmx + n, sz);
	mx.pb({curmx, "Kuro"});
	
	memset(hash, 0, sizeof(hash));
	curmx = 0;
	for(auto c : s2) {
		hash[c]++;
		curmx = max(curmx, hash[c]);
	} 
	if(curmx == sz && n == 1) curmx--;
	else curmx = min(curmx + n, sz);
	mx.pb({curmx, "Shiro"});
	
	memset(hash, 0, sizeof(hash));
	curmx = 0;
	for(auto c : s3) {
		hash[c]++;
		curmx = max(curmx, hash[c]);
	} 
	if(curmx == sz && n == 1) curmx--;
	else curmx = min(curmx + n, sz);
	mx.pb({curmx, "Katie"});
	
	sort(all(mx));
	
	if(mx[2].fi == mx[1].fi) {
		cout << "Draw" << endl;
	} else {
		cout << mx[2].se << endl;
	}
	return 0;
}
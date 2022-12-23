/*
	Author: MikiMiku
	
	Observation:
		1. At most we may only have 1 kind of
		character which have odd amount.
		
	Idea: 
		Here, the implementation is just straight-foward.
		We count how many characters of a certain alphabet
		that we have. After that to arrange the character
		that we have so the resulting string is palindrome,
		just divide the same character that we have
		into half. We push the first half and 
		do mirroring after that. So, it has the
		same amount as before. 
		
		But looking at this mechanism we just 
		need to handle when there is an odd amount 
		of character that we have, observation 1
		limits how much odd amount characters that
		we may have.
		
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

class PalindromeMaker {
	public:
	string make(string baseString) {
		int hash[27];
		memset(hash, 0, sizeof(hash));
		
		for(auto c : baseString) {
			hash[c - 'A']++;
		}
		
		string s1 = "";
		for(int i = 0; i < 26; ++i) {
			while(hash[i] > 1) {
				s1 += (char)(i + 'A');
				hash[i] -= 2;
			}
		}
		
		string s2 = s1; reverse(all(s2));
		
		string mid = "";
		for(int i = 0; i < 26; ++i) {
			if(hash[i]) {
				mid += (char)(i + 'A');
			}	
		}
		if(sza(mid) > 1) return "";
		
		string ans = s1 + mid + s2;
		return ans;
	}
};

/*
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	PalindromeMaker PM;
	string s;
	cin >> s;
	cout << PM.make(s);
	return 0;
}
*/
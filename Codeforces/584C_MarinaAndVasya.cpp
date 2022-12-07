/*
	Author: MikiMiku
	
	Definition:
		1. Let's define g(s1, s2) as how
		many same characters between s1 and s2.
	
	Observation:
		1. If n is the total length and t is
		the number of characters that need to be
		different, then n - t is the number of characters
		that need to be same.
		
	Idea: 
		By observation 1 we may see the task
		in another way which is we need exactly
		n - t same characters.
		
		To make it more clear on how to construct
		a string having n - t character. Let's
		say we have s1 and s2 as follows,
		
		n = 9, t = 5, n - t = 4
	s1	abcfdeegh 4 -> The character need to be same with s3 
	s2	cbffgdehi 4 -> We will name this parameter to "need"
	s3	.........
	
		Let's say we chose the first character to be
		'a' then,
	s1	abcfdeegh 3
	s2	cbffgdehi 4
	s3	a........
	
		Or if we chose it to be 'c'
		
	s1	abcfdeegh 4
	s2	cbffgdehi 3
	s3	c........
	
		Also we may choose to not make it same
		with any characters in s1 and s2.
		So, when s1[i] != s2[i] (0 <= i < n) then we have
		three choices, follow s1 character, follow
		s2, or not to ignore it and don't follow s1 or s2.
		
		But observe when s1[i] == s2[i] then we
		have two choices. Two have the same character
		with s1 and s2, or not.
		
		Remember that our current objective is to make
		the character need to make g(s1, s3) == g(s2, s3) == n - t.
		
		or
		
		make the 'character need to be same to be 0'
		
	s1	abcfdeegh 4 <- make it 0
	s2	cbffgdehi 4
	s3	.........
		
		for example,
		
	s1	abcfdeegh 0
	s2	cbffgdehi 0
	s3	bbafaaehh
	
		Notice that a "same" character can reduce 
		both "need" by 1 but we need two 
		"different" characters to reduce both "need"
		by 1. So the case when it's possible
		to make a third string (s3) is when we
		are running out the "same" and "different"
		characters to reduce "need" until 0. As if
		there is more "same" or "different" but
		"need" is 0 then we can just ignore all
		of that by taking characters that is
		different from s1 and s2, hence not
		reducing "need" any further.
		
		And the rest is that we need to construct
		s3. Which is can be done by marking every
		"same" and "different" that we take.
		
		But the implementation won't be discussed
		further as this idea has been too lengthy :').
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
int take[100007];

char other(char a, char b) {
	bool ch[26];
	memset(ch, 0, sizeof(ch));
	ch[a - 'a'] = 1;
	ch[b - 'a'] = 1;
	for(int i = 0; i < 26; ++i) {
		if(!ch[i]) return (char)(i + 'a');
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, t;
	cin >> n >> t;
	
	int need = n - t;
	
	string s1, s2;
	cin >> s1 >> s2;
	
	memset(take, 0, sizeof(take));
	
	vector<int> dif, same;
	for(int i = 0; i < n; ++i) {
		if(s1[i] == s2[i]) same.pb(i);
		else dif.pb(i);
	}
	
	while(need && sza(same)) {
		take[same.back()] = 1;
		same.pop_back();
		need--;
	}
	
	while(need && sza(dif) > 1) {
		int id1 = dif.back(); dif.pop_back();
		int id2 = dif.back(); dif.pop_back();
		take[id1] = 1;
		take[id2] = 2;
		need--;
	} 
	
	if(need) {
		cout << -1 << endl;
		return 0;
	}
	
	string ans = "";
	for(int i = 0; i < n; ++i) {
		if(take[i] == 0) {
			ans.pb(other(s1[i], s2[i]));
		} else if(take[i] == 1) {
			ans.pb(s1[i]);
		} else {
			ans.pb(s2[i]);
		}
	}
	
	cout << ans << endl;
	return 0;
}
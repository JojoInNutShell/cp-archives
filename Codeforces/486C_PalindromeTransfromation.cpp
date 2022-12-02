/*
	Author: MikiMiku
	
	Observation:
		1. Changing the already correct
		characeter to another character never
		improves final solution 
			
		2. If the pointer is mirrored, the
		final solution won't change.
		
		Just do mirroring movement on the
		normal solution.
		
	Idea:
		Firstly, we could just work on the first
		half side of the string as observation 1
		states that it's fine and better as it
		allow us to calculate the answer easier.
		
		The answer is just the sum of how many
		moves we make + how many change (up, down)
		to the character we need. Hence, it's
		ok to just calculate the change on character
		first and done the calculation on movement
		separately.
		
		If the pointer is located on the left
		and all the character that we need to change
		is on the right. Then the movement that we
		need is clear. It's from the pointer
		position to the righest character that we
		need to change.
		
		But what if it's both on the left
		and the right side of the pointer? 
		Then we just need to minimize the 
		overlapping movement that we make.
		We will go to the nearest end first
		the go to the another end, so we
		get the minimum movement to make.
		
		Watch out for the case as described above.
		(Including where string is already palindrome)
		
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
	int sz, pos;
	cin >> sz >> pos;
	cin >> s;

	pos--;
	if(pos >= (sz/2)) pos = (sz - 1) - pos;
	
	ll ans = 0;
	vector<int> idc;
	
	for(int i = 0; i < (sz/2); ++i) {
		if(s[i] != s[(sz - 1) - i]) {
			idc.eb(i);
			int cost = abs(s[i] - s[(sz - 1) - i]);
			ans += min(cost, 26 - cost);
		}
	}
	
	//Corner Case
	if(sza(idc) == 0) {
		cout << ans << endl;
		return 0;
	} else if(sza(idc) == 1) {
		ans += abs(idc[0] - pos);
		cout << ans << endl;
		return 0;
	}
	
	int dl = abs(idc[0] - pos), dr = abs(idc[sza(idc) - 1] - pos);
	if(pos <= idc[0]) {
		ans += dr;
	} else if(pos >= idc[sza(idc) - 1]) {
		ans += dl;
	} else {
		if(dl < dr) {
			ans += (2*dl + dr);
		} else {
			ans += (dl + 2*dr);
		}
	}
	
	cout << ans << endl;
	return 0;
}
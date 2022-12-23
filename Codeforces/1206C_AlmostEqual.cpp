/*
	Author: MikiMiku
	
	Observation:
		1. Let's assume we have construct
		the array with elements a1, a2, ... a2n.
		
		Then, all possible (set of) n consecutive numbers 
		are,
		
		a1, a2, a3, ..., an (Set 1)
		a2, a3, a4, ..., an+1 (Set 2)
		a3, a4, a5, ..., an+2 (Set 3)
		...
		a2n, a1, a2, ..., an-1 (Set n)
		
		Notice that the change from set i to i + 1 (or 1 if i == n)
		is just changing an element to another
		element. In case of set 1 to set 2,
		a1 is being replaced with an+1.
		
		Hence, a1 - an+1 = 1 or -1. 0 isn't
		possible as the change made won't be the
		same number again and any change larger
		than 1 or lower than -1 will definitely
		make the array an invalid construction.
		
		2. Continuing from observation 1, then
		suppose that a1 - an+1 = 1. To keep
		the array valid, a2 - an+2 must equal to
		-1 or -2 (But let's narrow it to just
		equal to -1 as we will construct it +1
		and -1 alternatingly to make it easier).
		
		The fact above must be true or else,
		set 1 and set 3 will differ by more than
		1.
		
		3. If n is even then there won't exist
		any array with the property as described
		in the task.
		
		The idea will give a feeling of why not. (Maybe)
		
	Idea: 
		By observation above, we will construct
		the array by this relation,
		
		ai    an+i
		1  ->  2   (+1)
		4  ->  3   (-1)
		5  ->  6   (+1)
		8  ->  7   (-1)
		...
		
		This will gurantee that set i and set j
		won't differ by more than 1.
		
		Let's assume that a1 = 1. Then,
		
		a1 - an+1 = -1 (Then a2 - an+2 = 1)
		1 + 1 = an+1
		2 = an+1
		
		a2 = 4 (Following the relation above)
		a2 - an+2 = 1
		4 - 1 = an+2
		3 = an+2
		
		and so on. But if we try with odd n, it
		won't work.
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
	
	if(n%2==0) {
		cout << "NO" << endl;
		return 0;
	}
	
	bool b = 0;
	vector<int> a1, a2;
	for(int i = 1; i <= 2*n; i += 2, b ^= 1) {
		if(b) {
			a1.pb(i + 1);
			a2.pb(i);
		} else {
			a1.pb(i);
			a2.pb(i + 1);
		}
	}
	
	cout << "YES" << endl;
	for(int i = 0; i < n; ++i) {
		cout << a1[i] << " ";
	}
	for(int i = 0; i < n; ++i) {
		cout << a2[i] << " ";
	} cout << endl;
	
	return 0;
}
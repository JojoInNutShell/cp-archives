/*
	Author: MikiMiku
	
	Definition:
		1. mx = maximum number in the array
		
		The rest goes like the task definition.
	
	Observation:
		1. Nor any player can add a number larger
		than the maximum number in the array.
		
		2. If there is 1 in the array, there
		must be mx - n number left that we could
		make (In other word it's possible to have
		number from 1 to mx in the array at the last move).
		
		We can do it this way,
		
			1. We add mx - 1 if that number
			wasn't there in the array.
			2. We add (mx - 1) - 1 if that number
			wasn't there in the array.
			3. We add (mx - 2) - 1 if that
			number wasn't there in the array.
			4. Keep going on until no more
			numbers could be added any more.
			
		3. The lowest number possible that can
		be added is gcd(a1, a2, ..., an).
		
		Notice that the operation of |ai - aj|
		where ai and aj is the first
		and second lowest number in the current array.
		
		Let's assume |aj - ai| = ak. Then ak <= ai.
		If ak < ai, then  we will have a new number to be
		the lowest one. If ak == ai then we can't have
		a number more lower than ai/ak.
		
		Also notice that doing |ai - aj| operation 
		repeatedly is synonymous to gcd operation.
		
		4. Let's assume we have the lowest number
		possible to be added (say lw) (Like what have been
		discussed in observation 3). Then at last
		all the numbers there will be in the
		array are,
		
		lw, 2*lw, 3*lw, ..., mx (k*lw) (for some integer k)
		
	Idea: 
		Recall that lw = gcd(a1, a2, ..., an).
		
		Then at last there will be mx/lw (say k) numbers
		in the array (Observation 4).
		
		Hence, there will only be n - k numbers
		more to be added. Where if n - k is odd,
		Alice must be winning, else Bob will win.
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
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int mx = 0;
	int gc = a[0];
	for(int i = 0; i < n; ++i) {
		mx = max(mx, a[i]);
		gc = __gcd(gc, a[i]);
	}
	
	int tot = mx/gc;
	int left = tot - n;
	if(left%2 == 1) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	return 0;
}
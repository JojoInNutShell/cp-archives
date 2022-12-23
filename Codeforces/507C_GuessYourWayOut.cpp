/*
	Author: MikiMiku
	
	Observation:
		
	Idea: 
		Let's say the current command is 'L'
		but the exit is located on the 'R' side 
		of the tree. It means that we must
		visit all the subtree on the 'L' side
		which mean we will visit 2^h - 1 more nodes
		for some h, plus the current node we are on.
		But if we the current command is 'L' and the
		exit also located on 'L' side, then we just
		need to count the current node we are on.
		
		By this implementation, we will count
		the root also (Even it should be ignored) but
		we won't count the leaf (No more ans++ at the end). 
		So the root count is for the leaf count.
		
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
	ll h, n;
	cin >> h >> n;
	
	ll l = 1, r = (1LL << h);
	char bef = 'L';
	ll ans = 0;
	while(l < r) {
		ll mid = (l + r)/2;
		
		if(n <= mid) {
			if(bef == 'L') {
				ans++;
			} else {
				ans += (1LL << h);
			}
			r = mid;
			bef = 'R';
		} else {
			if(bef == 'L') {
				ans += (1LL << h);
			} else {
				ans++;
			}
			l = mid + 1;
			bef = 'L';
		}
		
		h--;
	}
	
	cout << ans << endl;
	
	return 0;
}
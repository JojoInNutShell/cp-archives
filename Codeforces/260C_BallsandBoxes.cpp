/*
	Author: MikiMiku
	
	Idea: 
		We know the last index where the taken out
		balls are distributed. One way is that
		we could reverse the action by taking the 
		balls from where we distribute to until
		we encounter a place where there is no ball
		there (As it must be the place where we have
		taken the balls out). Then, we will just
		put our balls which we have collected, back
		again to the place where we took it.
		
		But, doing that will just lead us to TLE.
		We need to optimize the idea above a little
		bit more by noting that after some iteration
		we will stop taking balls when we encounter
		an empty box. That box must be the box with
		the most minimum amount of balls among
		the other box (after the action done).
		
		We know that if there is already at least
		an empty box. The iteration
		will finish before the N-th iteration.
		(Which won't lead us to TLE)
		
		We can first process the array given
		to have an empty box by substracting the balls
		in the box by the most minimum ai (element-i th).
		We are fast-forwarding our reverse action by that.
		
		After that we will just iterate it normally
		as explained above.
		
	Time Complexity : O(n)
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
	int n, x;
	cin >> n >> x;
	
	vector<ll> a(n);
	ll mn = 1e10;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	
	ll tot = mn*n;
	for(int i = 0; i < n; ++i) a[i] -= mn;
	
	x--;
	while(a[x] != 0) {
		a[x]--;
		tot++;
		
		x = (x == 0) ? n - 1 : x - 1;
	}
	a[x] = tot;
	
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	} cout << endl;
	return 0;
}
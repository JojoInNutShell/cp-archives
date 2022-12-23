/*
	Author: MikiMiku
	
	Idea: 
		Let's work on some example. Let's assume
		we have array from 1 to 5. Here are the
		simulation on the operation given:
		
		1 2 3 4 5 (The Array)
		5 4 3 2 1 (1 - 5)
		5 2 3 4 1 (2 - 4)
		5 2 3 4 1 (3 - 3)
		
		Let's see the operations applied on array
		from 1 to 6
		
		1 2 3 4 5 6 (The Array)
		6 5 4 3 2 1 (1 - 6)
		6 2 3 4 5 1 (2 - 5)
		6 2 4 3 5 1 (3 - 4)
		
		Observe the half of the array. If
		our indexing start from 0. Then the
		element with even index will be swapped
		by it's mirror (Which is in the last
		array, the mirror of 1 is 6, 2 is 5, etc.).
		But the odd index will stay in-place.
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
	
	n--;
	int i = (n/2);
	int j;
	if(n%2 == 1) j = i + 1;
	else j = i;
	
	for(; i >= 0; i--, j++) {
		if(i%2 == 0) {
			swap(a[i], a[j]);
		}
	}
	
	for(auto u : a) {
		cout << u << " ";
	} cout << endl;
	return 0;
}
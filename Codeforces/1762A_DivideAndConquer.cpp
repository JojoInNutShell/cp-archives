/*
	Author: MikiMiku
	
	Observation:
		1. The sum of the array given is odd if
		and only if there is an odd amount of odd
		number.
	
	Idea: 
		If the sum of the current array is even then
		no operation need to be done. Else, we
		need to do some operation, we will have
		two options, changing an odd number
		into an even number or changing an even number
		into an odd number. Then, we just need
		to choose one of those options with
		lowest operation needed.
		
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

int cnto(int u) {
	int c = 0;
	while(u%2==1) u>>=1, c++;
	return c;
}

int cnte(int u) {
	int c = 0;
	while(u%2==0) u>>=1, c++;
	return c;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		int odd = 0, cost = INF;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(a[i]%2 == 1) odd++, cost = min(cost, cnto(a[i]));
			else cost = min(cost, cnte(a[i]));
		}
		
		if(odd%2 == 0) {
			cout << 0 << endl;
		} else {
			cout << cost << endl;
		}
	}
	return 0;
}
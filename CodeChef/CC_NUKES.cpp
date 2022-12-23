/*
	Author: MikiMiku
	
	Idea: 
		At first there is A particles in chamber 1.
		See that when chamber 1 have more than N
		particles (A.K.A. N + 1 Particles). Then we
		will remove (N + 1) particles from chamber 1
		and add 1 particle to it's next chamber which
		is chamber 2.
		
		Notice that, at last the amount of particle
		at chamber 2 is k where k is the largest
		possible integer such that k*(N + 1) is <= A 
		(Which could be counted easily in C++ by A/(N + 1)).
		Hence, that also imply that the particle
		remaining in chamber 1 is A % (N + 1).
		
		The same idea also applies between chamber 2
		and chamber 3, chamber 3 and chamber 4 and so on.
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
	ll a, n, k;
	cin >> a >> n >> k;
	n++;
	
	vector<int> cham(k);
	cham[0] = a;
	
	for(int i = 1; i < k; ++i) {
		cham[i] = cham[i - 1]/n;
		cham[i - 1] %= n;
	} cham[k - 1] %= n;
	
	for(int i = 0; i < k; ++i) {
		cout << cham[i] << " ";
	} cout << endl;
	return 0;
}
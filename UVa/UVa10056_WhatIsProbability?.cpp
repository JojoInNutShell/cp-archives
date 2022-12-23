/*
	Author: MikiMiku
	
	Idea: 
		The winning probability of player 1 is
		
		p + p*(1 - p)^N + p*(1 - p)^2N + ...
		
		Player 1 can immediately win on first try, or
		he will wait for the next turn for the second
		try which mean N player need to lost once
		(which probability is (1 - p)^N ) at that
		round, or player 1 may win in his 3th try,
		or so on and so forth.
		
		We could generalize the winning probability
		of player N which is,
		
		p*(1 - p)^(i - 1) + p*(1 - p)^(i - 1 + N) +
		p*(1 - p)^(i - 1 + 2N) + ...
		
		Also we can simplify this further,
		
		p*(1 - p)^(i - 1)*(1 + (1 - p)^n + (1 - p)^2n
		+ (1 - p)^3n + ...)
		
		Notice that there is an infinite geometric
		series, which we may simplify to,
		
		p * (1 - p)^(i - 1) * ( 1/( 1 - (1 - p)^n ) )
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

double fexp(double b, int e) {
	if(e == 0) return 1;
	double half = fexp(b, e/2);
	if(e%2==1) return half*half*b;
	else return half*half;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(4);
	
	int T;
	cin >> T;
	while(T--) {
		double N, i;
		double p;
		cin >> N >> p >> i;
		
		if(p == 0.0) {
			cout << "0.0000" << endl;
			continue;
		}
		
		double ans = p*fexp(1 - p, i - 1)*(1/(1 - fexp(1 - p, N)));
		
		cout << ans << endl;
	}
	return 0;
}
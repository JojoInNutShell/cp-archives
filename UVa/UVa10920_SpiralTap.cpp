/*
	Author: MikiMiku
	
	Observation :
		1. Moving upper-right from starting point,
		the number that we will step on is
		in the form of (2*k + 1)^2 
		for some positive integer k.
		2. Every spiral will have cell number in range
		(k - 2)^2 + 1 to k^2 for some odd integer k >= 3.
	
	Idea: 
		Rather than thinking about current position
		we will calculate the displacement from
		the starting point.
		
		Let's say the x is the cell number that we
		want to find it's position
		
		We place ourself on cell with number (2*k + 1)^2.
		Where k is the smallest possible positive integer
		satisfying the inequality x <= (2*k + 1)^2.
		
		Then from there we just move backward spirally.
		(Of course not simulating per move)
		And be guranteed to find the cell number that
		we want before a full spiral.
		(Where a full spiral means we go from
		k^2 to (k - 2)^2 + 1)
		
		As our final answer just add the coordinate
		of the starting point with its displacement.
		
		Draw the spiral table to get better insight on it. 
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
	ll x, n;
	while(cin >> x >> n) {
		if(x == 0 && n == 0) break;
		
		ll sq = ceil(sqrt(n));
		if(sq % 2 == 0) sq++;
		ll up = sq*sq; ll mid = (x/2) + 1;
		
		ll posx = sq/2, posy = sq/2;
		if(up - (sq - 1) < n && n <= up) {
			ll dif = up - n;
			posy -= dif;
			
			ll ansx = mid + posx, ansy = mid + posy;
			cout << "Line = " << ansy << ", column = " << ansx << "." << endl;
			continue;
		}
		
		posy -= (sq - 1);
		up -= (sq - 1);
		
		if(up - (sq - 1) < n && n <= up) {
			ll dif = up - n;
			posx -= dif;
			
			ll ansx = mid + posx, ansy = mid + posy;
			cout << "Line = " << ansy << ", column = " << ansx << "." << endl;
			continue;
		}
		
		posx -= (sq - 1);
		up -= (sq - 1);
		
		if(up - (sq - 1) < n && n <= up) {
			ll dif = up - n;
			posy += dif;
			
			ll ansx = mid + posx, ansy = mid + posy;
			cout << "Line = " << ansy << ", column = " << ansx << "." << endl;
			continue;
		}
		
		posy += (sq - 1);
		up -= (sq - 1);
		
		ll dif = up - n;
		posx += dif;
		
		ll ansx = mid + posx, ansy = mid + posy;
		cout << "Line = " << ansy << ", column = " << ansx << "." << endl;

	}
	return 0;
}
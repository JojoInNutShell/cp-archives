/*
	Author: MikiMiku
	
	Idea: 
		Here, we need to find ( '|' is given that )
		p(i is buying something | r people buy something)
		for every 1 <= i <= N.
		We could enumerate this using bitmask/string.
		For example : (Let's say we have 3 people)
		
		123 (Column 1 for friend 1, column 2 for friend 2, and so on)
		001 (friend 1 is buying something) (The probability of this event is (1 - p1)*(1 - p2)*p3 )
		101 (friend 1 and 3 is buying something) (The probability of this event is p1*(1 - p2)*p3 )
		
		We know that P(A|B) = P(A n B)/P(B) ( 'n' is and )
		
		The we just need to enumerate all possible
		combination of bitmask/string containing
		r 1's.
		
		Say we want the probability of friend 1
		buying something with N = 3, r = 2;
		Hence, our answer will be
		
		p(101) + p(110)
		------------------------ (Divided by)
		p(101) + p(110) + p(011) (The event '011' is not included above because there is no friend 1 in it)
		
		The same idea applies to 
		find the probability for
		friend 2 and 3.
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
vector<double> pi;

double prob(string s) {
	double res = 1;
	for(int i = 0; i < sza(s); ++i) {
		if(s[i] == '0') res *= (1 - pi[i]);
		else res *= pi[i];
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	
	int N, r;
	int tc = 1;
	while(cin >> N >> r) {
		if(N == 0 && r == 0) break;
		
		cout << "Case " << tc++ << ":" << endl;
		
		pi.assign(N, 0);
		for(int i = 0; i < N; ++i) cin >> pi[i];
		
		for(int i = 0; i < N; ++i) {
			string bs;
			double pibuy = 0;
			double prbuy = 0;
			
			for(int j = 0; j < (N - r); ++j) bs += '0';
			for(int j = 0; j < r; ++j) bs += '1';
			
			double cur = prob(bs);
			if(bs[i] == '1') pibuy += cur;
			prbuy += cur;
			
			while(next_permutation(all(bs))) {
				cur = prob(bs);
				if(bs[i] == '1') pibuy += cur;
				prbuy += cur;
			}
			
			double ans = pibuy/prbuy;
			cout << ans << endl;
		}
	}
	return 0;
}
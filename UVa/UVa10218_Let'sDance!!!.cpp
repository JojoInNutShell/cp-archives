/*
	Author: MikiMiku
	
	Definition:
		pw : Probability of woman getting candies
		pm : Probability of man getting candies
		The rest is the same as the task.
	
	Idea: 
		The probability of some man getting candy
		is m/(m + w). The woman is w/(m + w).
		We just need to sum all probability where
		the coins given to men are even.
		
		Which is when there is 0, 2, 4, ... coins
		from men. The probability of that event
		is pw^(How many candies that women got) * 
		pm^(How many candies that men got).
		Not to forget that there is C choose i
		(where i is the coin that men got) event.
		
		So, the probability of event where men
		got i coins is,
		
		pw^(C - i) * pm^(i) * (C choose i)
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
double pascal[107][107];

void init() {
	memset(pascal, 0, sizeof(pascal));
	for(int i = 0; i < 101; i++) {
		pascal[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
		} 
	}
}


signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	init();
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(7);
	
	int m, w, c;
	while(cin >> m >> w >> c) {
		if(m == 0 && w == 0) break;
		
		double pw = (double)w/(double)(m + w);
		double pm = 1 - pw;
		double res = 0;
		for(int i = 0; i <= c; i += 2) {
			int count_woman = c - i;
			double prob = pow(pw, count_woman)*pow(pm, i);
			double way = pascal[c][i];
			res += prob*way;
		}
		cout << res << endl;
	}
	return 0;
}
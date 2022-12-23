/*
	Author: MikiMiku
	
	Idea: 
		We are going to be greedy here. We have
		to construct a pile such that for every
		pile that we make we could have as many
		box as possible in it. 
		
		To accomplish that we will construct the
		pile as follow, we are building the pile
		from the top. At first the pile has size 0,
		so we may have box with strengh 0 or larger
		there, after that the pile has size 1, then
		we may put a box with strength 1 or larger
		there, and we keep repeating the step
		while there is a box that has strength egual
		to or larger than the size of current pile
		(Of course because we need that kind of
		box to maintain a valid pile)
		(This could be done by binary search),
		else we will make new pile while there
		is box left to make pile.
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
	
	map<int, int> mint;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mint[a]++;
	}
	
	int c = 0;
	while(!mint.empty()) {
		c++;
		int sz = 0;
		while(mint.lower_bound(sz) != mint.end()) {
			auto it = mint.lower_bound(sz);
			int cur = (*it).fi;
			
			mint[cur]--;
			if(mint[cur] == 0) mint.erase(cur);
			sz++;
		}
	}
	
	cout << c << endl;
	return 0;
}
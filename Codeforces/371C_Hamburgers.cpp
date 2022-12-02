#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
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
	string rec;
	cin >> rec;
	ll needB = 0, needS = 0, needC = 0;
	for(auto c : rec) {
		if(c == 'B') needB++;
		else if(c == 'S') needS++;
		else needC++;
	}
	ll nB, nS, nC;
	cin >> nB >> nS >> nC;
	ll pB, pS, pC;
	cin >> pB >> pS >> pC;
	ll rub;
	cin >> rub;
	
	ll l = 0, r = 1e14;
	while(l < r) {
		ll cur = (l + r + 1)/2;
		ll sum = 0;
		sum += (max((needB*cur) - nB, 0LL))*pB;
		sum += (max((needS*cur) - nS, 0LL))*pS;
		sum += (max((needC*cur) - nC, 0LL))*pC;
		if(sum > rub) {
			r = cur - 1;
		} else {
			l = cur;
		}
	}
	cout << l << endl;
	return 0;
}
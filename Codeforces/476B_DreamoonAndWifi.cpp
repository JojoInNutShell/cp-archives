#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
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
//........................................................................
int onecounter(int n, int c = 0) {
	if(n == 0) return 0;
	if(n == 1) return c + 1;
	if(n%2 == 0) {
		return onecounter(n/2, c);
	} else {
		return onecounter(n/2, c + 1);
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s1, s2;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(9);
	cin >> s1 >> s2;
	int nq = 0, vals1 = 0, vals2 = 0;
	for(auto c : s1) {
		if(c == '+') vals1++;
		if(c == '-') vals1--;
	}
	for(auto c : s2) {
		if(c == '+') vals2++;
		if(c == '-') vals2--;
		if(c == '?') nq++;
	}
	if(nq == 0 && vals1 == vals2) {
		cout << 1;
		return 0;
	} else if(nq == 0 && vals1 != vals2) {
		cout << 0;
		return 0;
	}
	int u = pow(2, nq), valid = 0;
	for(int i = 0; i < u; ++i) {
		int c = onecounter(i);
		if(vals1 == vals2 + c - (nq - c)) {
			valid++;
		}
	}
	cout << (double)valid/(double)u;
	return 0;
}
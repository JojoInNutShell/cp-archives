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
array<int, 26> chdat;

/*
void printarr() {
	for(auto val : chdat) {
		cout << val << " ";
	}
	cout << endl;
}
*/

void first();
void second();

bool isPalindrome() {
	int o = 0;
	for(auto val : chdat) {
		if(val % 2 == 1) o++;
	}
	if(o < 2) return true;
	else return false;
}

void first() {
	if(isPalindrome()) {
		cout << "First";
		return;
	}
	int opos, idx = 0;
	for(auto& val : chdat) {
		if(val % 2 == 0 && val != 0) {
			val--;
			return second();
		} else if(val % 2 == 1) {
			opos = idx;
		}
		idx++;
	}
	chdat[opos]--;
	return second();
}

void second() {
	if(isPalindrome()) {
		cout << "Second";
		return;
	}
	int opos,idx = 0;
	for(auto& val : chdat) {
		if(val % 2 == 0 && val != 0) {
			val--;
			return first();
		} else if(val % 2 == 1) {
			opos = idx;
		}
		idx++;
	}
	chdat[opos]--;
	return first();
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s;
	cin >> s;
	for(auto c : s) chdat[c - 'a']++;
	first();
	return 0;
}
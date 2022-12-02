#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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
map<char, char> mirrorList({{'A', 'A'}, {'E', '3'}, {'3', 'E'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'L', 'J'}, {'M', 'M'}, {'O', 'O'}, {'S', '2'}, {'2', 'S'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'Z', '5'}, {'5', 'Z'}, {'1', '1'}, {'8', '8'}});

bool isPalindrome(string s, int l, int r) {
	if(l >= r) {
		return true;
	} else {
		if(s[l] == s[r]) {
			return isPalindrome(s, l + 1, r - 1);
		} else {
			return false;
		}
	}
}

bool isMirror(string s, int l, int r) {
	if(l > r) {
		return true;
	} else if(l == r) {
		auto p1 = mirrorList.find(s[l]);
		if(p1 == mirrorList.end()) {
			return false;
		}
		if((*(p1)).fi == (*(p1)).se) {
			return true;
		} else {
			return false;
		}
	} else {
		auto p1 = mirrorList.find(s[l]);
		if(p1 == mirrorList.end()) {
			return false;
		} else {
			if((*(p1)).se == s[r]) {
				return isMirror(s, l + 1, r - 1);
			} else {
				return false;
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s, temps;
	bool ispalin, ismir;
	while(cin >> temps) {
		s = temps;
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		ispalin = false; ismir = false;
		ispalin = isPalindrome(s, 0, sza(s) - 1);
		ismir = isMirror(s, 0, sza(s) - 1);
		if(ispalin && ismir) {
			cout << s << " -- is a mirrored palindrome.";
		} else if(ispalin) {
			cout << s << " -- is a regular palindrome.";
		} else if(ismir) {
			cout << s << " -- is a mirrored string.";
		} else {
			cout << s << " -- is not a palindrome.";
		} cout << endl << endl;
	}
	return 0;
}
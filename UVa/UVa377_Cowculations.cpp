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
map<char, int> csTonum({{'V', 0}, {'U', 1}, {'C', 2}, {'D', 3}});
array<int, 8> num1, num2, numres;

void addop() {
	int c;
	for(int i = 0; i < 8; ++i) {
		num2[i] += num1[i];
		c = i;
		while(num2[c] > 3) {
			num2[c] -= 4;
			num2[c + 1] += 1;
			c++;
		}
	}
	/*
	for(int i = 7; i >= 0; --i) {
		cerr << num2[i] << " ";
	}
	cerr << endl << endl;
	*/
}

void leftop() {
	for(int i = 7; i >= 1; --i) {
		num2[i] = num2[i - 1];
	}
	num2[0] = 0;
}

void rightop() {
	for(int i = 1; i < 8; ++i) {
		num2[i - 1] = num2[i];
	}
	num2[7] = 0;
}

bool isSame() {
	for(int i = 0; i < 8; ++i) {
		if(num2[i] != numres[i]) return false;
	}
	return true;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	cout << "COWCULATIONS OUTPUT" << endl;
	while(T--) {
		string s1, s2;
		array<char, 3> op;
		string res;
		cin >> s1 >> s2 >> op[0] >> op[1] >> op[2] >> res;
		num1.fill(0); num2.fill(0); numres.fill(0);
		reverse(all(s1)); reverse(all(s2)); reverse(all(res));
		int c = 0;
		for(auto ch : s1) num1[c++] = csTonum[ch];
		c = 0;
		for(auto ch : s2) num2[c++] = csTonum[ch];
		c = 0;
		for(auto ch : res) numres[c++] = csTonum[ch];
		for(auto ch : op) {
			if(ch == 'A') {
				addop();
			} else if(ch == 'L') {
				leftop();
			} else if(ch == 'R') {
				rightop();
			}
		}
		/*
		for(int i = 7; i >= 0; --i) {
			cerr << num2[i] << " ";
		}
		cerr << endl;
		for(int i = 7; i >= 0; --i) {
			cerr << numres[i] << " ";
		}
		cerr << endl << endl;
		*/
		if(isSame()) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
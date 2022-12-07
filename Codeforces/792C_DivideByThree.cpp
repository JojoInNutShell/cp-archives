/*
	Author: MikiMiku
	
	Observation:
		1. A number is divisible by 3 if and
		only if the sum of it's digit is divisible
		by 3.
		
		2. Erasing digit 3,6,9 never improves
		our final solution.
		
		This follows from observation 1. As deleting
		them won't gurantee the final
		solution to be divisible by 3.
		
		3. If there is more than one choice of 
		deleting digit(s). Then erasing the larger
		index first is alwyas a better thing to do.
		
		As this may prevent the final solution
		to have leading zeros.
		
	Idea: 
		We will divide the case by current
		remainder of the number given :
		1. When the remainder is 0, then we don't
		need to change anything in the number.
		2. When the remainder is 1, then there is
		only two possible best answer the first
		is to delete a digit with remainder 1 or
		to delete two digit with remainder 2.
		(There is two possible best answer
		because we have to delete leading zeros
		later on, making deleting "a digit" option
		not always the better one)
		3. When the remainder is 2, then there is
		only two possible best answer the first
		is to delete a digit with remainder 2 or
		to delete two digit with remainder 1.
		
		For the implementation just follow from
		the observation. We need to be greedy but
		also to be a bit careful for some cases.
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
vector<int> pos;
bool suc;

void sfind(string s, int p, int m) {
	pos.clear(); suc = true;
	for(int i = sza(s) - 1; i >= 0 && m; --i) {
		int cur = s[i] - '0';
		if((cur%3)==p) {
			pos.pb(i);
			m--;
		}
	}
	if(m) suc = false;
	
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	
	string s;
	cin >> s;
	
	int parity = 0;
	
	for(int i = 0; i < sza(s); ++i) {
		parity += (s[i] - '0'); parity %= 3;
	}
	
	string sans1 = "", sans2 = "";
	if(parity == 0) {
		sans1 = s;
	} else if(parity == 1) {
		sfind(s, 1, 1);
		if(suc) {
			sans1 = s;
			for(auto i : pos) {
				sans1.erase(i, 1);
			}
		} 
		sfind(s, 2, 2);
		if(suc) {
			sans2 = s;
			for(auto i : pos) {
				sans2.erase(i, 1);
			}
		}
	} else {
		sfind(s, 2, 1);
		if(suc) {
			sans1 = s;
			for(auto i : pos) {
				sans1.erase(i, 1);
			}
		} 
		sfind(s, 1, 2);
		if(suc) {
			sans2 = s;
			for(auto i : pos) {
				sans2.erase(i, 1);
			}
		}
	}
	
	reverse(all(sans1));
	while(sans1.back() == '0' && sza(sans1) > 1) sans1.pop_back();
	reverse(all(sans1));
	
	reverse(all(sans2));
	while(sans2.back() == '0' && sza(sans2) > 1) sans2.pop_back();
	reverse(all(sans2));
	
	if(sza(sans1) == 0 && sza(sans2) == 0) {
		cout << -1 << endl;
	} else {
		if(sza(sans1) > sza(sans2)) {
			cout << sans1 << endl;
		} else cout << sans2 << endl;
 	}
	
	return 0;
}
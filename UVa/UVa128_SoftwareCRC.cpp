/*
	Author: MikiMiku
	
	Idea: (More of explanation)
		We convert the string into 
		"the long positive binary number"
		but for something like that we could
		just work by decimal base while implementing
		the mechanism prescribed on the statement.
		We give 8-bit (ASCII size) distance
		for every character and at last
		spare 16-bit for the CRC value which
		is a number (say c), the remainder of the 
		last sum after divided by 34943 we get by 
		following the mechanism (say r)
		such that 34943 = c + r or c = 34943 - 
		(so that the m2 is divisible by 34943), 
		then just convert c to hex
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
const ll MOD = 34943;
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
	string s;
	while(getline(cin, s)) {
		if(s == "#") break;
		if(s == "") {cout << "00 00" << endl; continue;}
		
		ll sum = 0;
		for(int i = 0; i < sza(s); ++i) {
			sum %= MOD;
			sum <<= 8;
			sum += s[i];
		}
		sum <<= 16;
		sum = MOD - (sum % MOD);
		
		stringstream ss;
		ss << uppercase << hex << sum << endl;
		
		string hx;
		ss >> hx;
		
		reverse(all(hx));
		while(sza(hx) < 4) hx += '0';
		reverse(all(hx));
		
		cout << hx[0] << hx[1] << " " << hx[2] << hx[3] << endl;
	}
	return 0;
}
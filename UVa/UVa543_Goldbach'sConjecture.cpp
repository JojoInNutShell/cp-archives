#include <bits/stdc++.h>
using namespace std;

#define int long long
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
//........................................................................
bitset<1100000> isPrime;
vector<int> listPrime;
ll _sieve_size;

void sieve(int upbound) {
	_sieve_size = upbound + 1;
	isPrime.set();
	isPrime[0] = false;
	isPrime[1] = false;
	//isPrime[2] = false;
	for(int i = 2; i <= _sieve_size; ++i) {
		if(isPrime[i]) {
			for(int j = i*i; j <= _sieve_size; j += i) {
				//cerr << j << " ";
				isPrime[j] = false;
			}
			listPrime.pb(i);
		}
		//cerr << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	sieve(1000000); isPrime[2] = false;
	while(cin >> n) {
		if(n < 6) break;
		if(n % 2 == 1) {
			cout << "Goldbach's conjecture is wrong." << endl;
			continue;
		}
		bool Gcon = false;
		for(auto p : listPrime) {
			if(p == 2) continue;
			if(p > n) break;
			if(isPrime[n - p]) {
				cout << n << " = " << p << " + " << n - p << endl;
				Gcon = true;
				break;
			}
		}
		if(!Gcon) {
			cout << "Goldbach's conjecture is wrong." << endl;
		}
	}
	return 0;
}
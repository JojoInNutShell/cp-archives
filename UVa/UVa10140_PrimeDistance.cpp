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
bitset<10000006> bs;
vector<int> primeList;
ll _sieve_size;

void sieve(int upbound) {
	_sieve_size = upbound + 1;
	bs.set();
	bs[0] = false;
	bs[1] = false;
	for(int i = 2; i <= _sieve_size; ++i) {
		if(bs[i]) {
			for(int j = i*i; j <= _sieve_size; j += i) {
				bs[j] = false;
			}
			//cerr << i << endl;
			primeList.pb(i);
		}
	}
}

bool isPrime(int n) {
	if(n <= _sieve_size) return bs[n];
	else {
		for(int i = 0; i < sza(primeList); ++i) {
			if(primeList[i] * primeList[i] > n) return true;
			if(n % primeList[i] == 0) return false;
		}
		return true;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll l, r;
	sieve(10000000);
	while(cin >> l >> r) {
		vector<int> primeRange;
		for(int i = l; i <= r; ++i) {
			if(isPrime(i)) {
				//cerr << i << endl;
				primeRange.pb(i);
			}
		}
		int sz = sza(primeRange);
		if(sz < 2) {
			cout << "There are no adjacent primes." << endl;
			continue;
		}
		int distmin = INF; int mina, minb;
		int distmax = 0; int maxa, maxb;
		for(int i = 1; i < sz; ++i) {
			//cerr << primeRange[i - 1] <<  " " << primeRange[i] << endl;
			if(primeRange[i] - primeRange[i - 1] < distmin) {
				mina = primeRange[i - 1];
				minb = primeRange[i];
				distmin = primeRange[i] - primeRange[i - 1];
			}
			if(primeRange[i] - primeRange[i - 1] > distmax) {
				maxa = primeRange[i - 1];
				maxb = primeRange[i];
				distmax = primeRange[i] - primeRange[i - 1];
			}
		}
		cout << mina << ","  << minb << " are closest, " << maxa << "," << maxb << " are most distant." << endl;
	}
	return 0;
}
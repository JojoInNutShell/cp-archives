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
bitset<20000006> bs;
vector<int> primes;
vector<ii> twins;
ll _sieve_size;
int a, b;

void sieve(ll upbound) {
	_sieve_size = upbound + 1;
	bs.set();
	bs[0] = false; 
	bs[1] = false;
	bool isTwo = true; //int idx = -1;
	for(int i = 2; i <= _sieve_size; ++i) {
		if(bs[i]) {
			for(int j = i*i; j <= _sieve_size; j += i){
				bs[j] = false;
			}
			b = i;
			if(isTwo) isTwo = false, a = i;
			else if(b - a == 2) {
				//cerr << primes[idx] << " " << primes[idx - 1] << endl;
				twins.pb({a, b});
			}
			swap(a, b);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	sieve(20000000);
	cerr << sza(twins);
	
	while(cin >> n) {
		cout << "(" << twins[n - 1].fi << ", " << twins[n - 1].se << ")" << endl;
	}
	return 0;
}
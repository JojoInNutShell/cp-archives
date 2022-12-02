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
array<int, 1000006> mu, M;
bitset<1000006> bs;
ll SieveSize;

void sieve(int u) {
	SieveSize = u + 1;
	bs.set(); bs[0] = bs[1] = false;
	mu.fill(1); M.fill(0); M[1] = 1, mu[1] = 1;
	for(int i = 2; i <= SieveSize; ++i)  {
		if(bs[i]) {
			for(int j = 2*i; j <= SieveSize; j += i) {
				if(j % (i*i) == 0) mu[j] = 0;
				mu[j] *= -1;
				bs[j] = false;
			}
			mu[i] = -1;
		}
		M[i] = mu[i] + M[i - 1];
		//cerr << i << " " << mu[i] << " " << M[i] << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	sieve(1000000);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		cout << right << setw(8) << n;
		cout << right <<  setw(8) << mu[n];
		cout << right <<  setw(8) << M[n];
		cout << endl;
		//cout << n << " " << mu[n] << " " << M[n] << endl;
	}
	return 0;
}
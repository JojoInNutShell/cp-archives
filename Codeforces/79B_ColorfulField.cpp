#include <bits/stdc++.h>
using namespace std;

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
multiset<pair<int, int>> arr;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, k, q, a, b, qr, qc;
	cin >> n >> m >> k >> q;
	for(int i = 0; i < k; ++i) {
		cin >> a >> b;
		arr.insert(mp(a, b));
	}
	int dis, tot, res;
	for(int i = 0; i < q; ++i) {
		cin >> qr >> qc;
		if(arr.find(mp(qr, qc)) != arr.end()) {
			cout << "Waste" << endl;
			continue;
		}
		dis = distance(arr.begin(), arr.lower_bound(mp(qr, qc)));
		tot = m*(qr - 1) + (qc - 1);
		res = tot - dis;
		if(res % 3 == 0) {
			cout << "Carrots";
		} else if(res % 3 == 1) {
			cout << "Kiwis";
		} else {
			cout << "Grapes";
		}
		cout << endl;
		
	}
	return 0;
}
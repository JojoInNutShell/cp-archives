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
vector<vector<int>> listt;
vector<int> arr, tail;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int t, len;
	while(cin >> t) {
		arr.pb(t);
	}
	if(sza(arr) == 0) {
		cout << 0 << endl << "-";
		return 0;
	}
	listt.pb({arr[0]}); tail.pb(arr[0]); len = 1;
	for(auto elem : arr) {
		auto it = lower_bound(tail.begin(), tail.end(), elem);
		if(it == tail.begin()) {
			listt[0] = {elem}; tail[0] = elem;
		} else if(it == tail.end()) {
			listt.pb({});
			copy(listt[len - 1].begin(), listt[len - 1].end(), back_inserter(listt[len]));
			listt[len].pb(elem); tail.pb(elem);
			len++;
		} else {
			int pos = (it - tail.begin());
			listt[pos].clear();
			copy(listt[pos - 1].begin(), listt[pos - 1].end(), back_inserter(listt[pos]));
			listt[pos].pb(elem);
			tail[pos] = elem;
		}
	}
	cout << sza(listt[len - 1]) << endl << "-" << endl;
	for(auto val : listt[len - 1]) {
		cout << val << endl;
	}
	return 0;
}
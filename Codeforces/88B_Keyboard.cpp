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
array<vector<pair<double, double>>, 300> arr;
map<char, int> printable;

double edist(double x1, double y1, double x2, double y2) {
	return sqrt((abs(x1 - x2) * abs(x1 - x2)) + (abs(y1 - y2)*abs(y1 - y2)));
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, x;
	cin >> n >> m >> x;
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		for(int j = 0; j < m; ++j) {
			arr[s[j]].pb(mp(i + 0.5, j + 0.5));
		}
	}
	int q, cnt = 0;
	string qs;
	cin >> q;
	cin >> qs;
	for(auto c : qs) { //Make corener case for S
		char cur = tolower(c);
		if(printable.find(c) != printable.end()) {
			cnt += printable[c];
			continue;
		}
		if(arr[cur].empty()) {
			cout << -1;
			return 0;
		}
		if(97 <= c && c <= 122) {
			printable.insert(mp(c, 0));
			continue;
		} else {
			if(arr['S'].empty()) {
				cout << -1;
				return 0;
			} else {
				double lo = INF;
				for(auto spos : arr['S']) {
					for(auto cpos : arr[cur]) {
						lo = min(lo, edist(spos.fi, spos.se, cpos.fi, cpos.se));
					}
				}
				if(lo > x) {
					++cnt;
					printable.insert(mp(c, 1));
				} else {
					printable.insert(mp(c, 0));
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
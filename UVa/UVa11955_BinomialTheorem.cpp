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
int pascal[100][100];

void precompute() {
	pascal[0][0] = 1;
	for(int i = 1; i < 52; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0 || j == i) {
				pascal[i][j] = 1;
			} else {
				pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
			}
			//cerr << pascal[i][j] << " ";
		}
		//cerr << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	precompute();
	cin >> T;
	for(int tc = 1; tc <= T; ++tc) {
		cout << "Case " << tc << ": ";
		string s;
		cin >> s;
		string var_a = s.substr(1, s.find("+") - 1);
		string var_b = s.substr(s.find('+') + 1, s.find(')') - s.find('+') - 1);
		int po = stoi(s.substr(s.find('^') + 1));
		//cerr << var_a << " " << var_b << " " << po << endl;
		vector<string> ans(po + 1);
		for(int l = po, r = 0; l >= 0; --l, ++r) {
			if(r == 0) {
				ans[r] += var_a;
				if(l > 1) {
					ans[r] += '^';
					ans[r] += to_string(po);
				}
			} else if(l == 0) {
				ans[r] += var_b;
				if(r > 1) {
					ans[r] += '^';
					ans[r] += to_string(po);
				}
			} else {
				if(pascal[po][r] > 1) {
					ans[r] += to_string(pascal[po][r]);
					ans[r] += '*';
				}
				ans[r] += var_a;
				if(l > 1) {
					ans[r] += '^';
					ans[r] += to_string(l);
				}
				ans[r] += '*';
				ans[r] += var_b;
				if(r > 1) {
					ans[r] += '^';
					ans[r] += to_string(r);
				}
				
			}
		}
		for(int i = 0; i <= po; ++i) {
			if(i != 0) cout << '+';
			//cerr << ans[i] << endl;
			cout << ans[i];
		}
		cout << endl; //cerr << endl;
 	}
	return 0;
}
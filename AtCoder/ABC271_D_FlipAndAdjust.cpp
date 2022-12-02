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
array<bitset<10006>, 106> memo;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, sum;
	cin >> n >> sum;
	vector<int> a(n), b(n), arr(n);
	int cur = 0;
	string ans = "";
	for(int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		if(a[i] < b[i]) {
			cur += a[i];
			ans += 'H';
		} else {
			cur += b[i];
			ans += 'T';
		}
		arr[i] = abs(a[i] - b[i]);
		//cerr << i << " : " << arr[i] << endl;
		//cerr << arr[i] << endl;
	}
	//cerr << endl;
	int need = sum - cur;
	//cerr << need << endl;
	if(need < 0) {
		cout << "No" << endl;
		return 0;
	}
	if(need == 0) {
		cout << "Yes" << endl;
		cout << ans << endl;
		return 0;
	}
	for(auto& bs : memo) bs.set(0);
	for(int i = 1; i <= n; ++i) {
		memo[i][arr[i - 1]] = true;
		for(int s = 0; s <= 10000; ++s) {
			if(s == 0) memo[i][s] = true;
			memo[i][s] = (memo[i - 1][s] | (s - arr[i - 1] >= 0 ? memo[i - 1][s - arr[i - 1]] : false));
		}
	}
	if(memo[n][need]) {
		int pos = need, i = n;
		while(i > 0) {
			if(memo[i - 1][pos]) {
				//cerr << i << " : 1" << endl;
				--i;
				continue;
			} else if((pos - arr[i - 1] >= 0 ? memo[i - 1][pos - arr[i - 1]] : false)) {
				//cerr << i << " : 2" << endl;
				pos -= arr[i - 1];
				if(ans[i - 1] == 'H') ans[i - 1] = 'T';
				else ans[i - 1] = 'H';
				--i;
			} else {
				//cerr << i << " : 3" << endl;
				if(ans[i - 1] == 'H') ans[i - 1] = 'T';
				else ans[i - 1] = 'H';
				break;
			}
		}
		/*
		for(i = 0; i <= need; i++) {
			for(int j = 0; j <= n; ++j) {
				cerr << memo[j][i] << " ";
			}
			cerr << endl;
		}
		*/
		cout << "Yes" << endl;
		cout << ans << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
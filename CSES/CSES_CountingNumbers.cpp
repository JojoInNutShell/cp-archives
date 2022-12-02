#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int memo[20][10][2];
int pc[19];
string a, b;

int dp(int i, int bf, int lock, string s) {
	if(memo[i][bf][lock] != 0) return memo[i][bf][lock];
	else {
		if(i == sza(s)) return memo[i][bf][lock] = 1;
		else {
			int res = 0;
			int b = s[i] - '0';
			//cerr << b << endl;
			if(lock) {
				for(int num = (i == 0 ? 1 : 0); num < b; ++num) {
					if(num == bf) continue;
					else res += dp(i + 1, num, 0, s);
				}
				if (b != bf) res += dp(i + 1, b, 1, s);
				return memo[i][bf][lock] = res;
			} else {
				for(int num = 0; num < 10; ++num) {
					if(num == bf) continue;
					else res += dp(i + 1, num, 0, s);
				}
				return memo[i][bf][lock] = res; 
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	pc[0] = 1;
	for(int i = 1; i <= 18; ++i) {
		pc[i] = 9*pc[i - 1];
	}
	
	int mul, id;
	int na, nb;
	cin >> na >> nb;
	a = to_string(na);
	b = to_string(nb);
	
	int ne = -1;
	char c = 'a';
	for(auto ch : a) {
		if(c == ch) {
			ne = 0;
			break;
		}
		else c = ch;
	}
	
	//cerr << na << " " << nb << endl;
	memset(memo, 0, sizeof(memo));
	int vala = dp(0, 0, 1, a);
	mul = 10; id = 1;
	while(na >= mul) {
		vala += pc[id];
		id++; mul *= 10;
	}
	memset(memo, 0, sizeof(memo));
	int valb = dp(0, 0, 1, b);
	mul = 10; id = 1;
	while(nb >= mul) {
		valb += pc[id];
		id++; mul *= 10;
	}
	vala += ne;
	//cerr << vala << " " << valb;
	int ans = (valb - vala);
	cout << ans;
	
	return 0;
}
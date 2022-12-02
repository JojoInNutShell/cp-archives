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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................
int n, m;

string land[206];
bool landb[206][206];
int landw[206][206];

bool isValid(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < m) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 0; i < n; ++i) cin >> land[i];
		
		memset(landb, 0, sizeof(landb));
		
		queue<ii> q;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(land[i][j] == '1') q.push({i, j}), landb[i][j] = true, landw[i][j] = 0;
			}
		}
		
		vector<ii> mv({{1,0}, {-1, 0}, {0, 1}, {0, - 1}});
		
		while(!q.empty()) {
			ii p;
			p = q.front(); q.pop();
			int i = p.fi, j = p.se;
			//cerr << i << " " << j << endl;
			landb[i][j] = true;
			
			for(auto m : mv) {
				if(isValid(i + m.fi, j + m.se) && !landb[i + m.fi][j + m.se]) {
					q.push(mp(i + m.fi, j + m.se));
					landw[i + m.fi][j + m.se] = landw[i][j] + 1;
					//cerr << i + m.fi << " " << j + m.se << " " << landw[i][j] + 1 << endl;
					landb[i + m.fi][j + m.se] = true;
				}
			}
		}
		
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				cout << landw[i][j] << " ";
			} cout << endl;
		}
	}
	return 0;
}
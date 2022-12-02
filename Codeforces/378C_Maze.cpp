/*
	Author: MikiMiku
	
	Idea: 
		We could do DFS on the valid path
		with length s - k, one can see that
		the DFS is always connected so we
		could use that connected graph as our
		answer and mark the other as X
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
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
string tab[507];
bool btab[507][507];
vector<ii> a;
set<ii> st;
int n, m, k;

bool isValid(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < m) return true;
	else return false;
}

void dfs(int i, int j) {
	if(k == 0) return;
	//cerr << i << " " << j << endl;
	
	btab[i][j] = true;
	st.insert({i, j});
	k--;
	
	int ni, nj;
	
	ni = i + 1, nj = j;
	if(isValid(ni, nj) && !btab[ni][nj] && tab[ni][nj] == '.') dfs(ni, nj);
	
	ni = i - 1, nj = j;
	if(isValid(ni, nj) && !btab[ni][nj] && tab[ni][nj] == '.') dfs(ni, nj);
	
	ni = i, nj = j + 1;
	if(isValid(ni, nj) && !btab[ni][nj] && tab[ni][nj] == '.') dfs(ni, nj);
	
	ni = i, nj = j - 1;
	if(isValid(ni, nj) && !btab[ni][nj] && tab[ni][nj] == '.') dfs(ni, nj);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n >> m >> k;
	int hsh = 0;
	for(int i = 0; i < n; ++i) {
		cin >> tab[i];
		for(int j = 0; j < m; ++j) {
			if(tab[i][j] == '#') hsh++;
		}
	}
	k = (n*m) - hsh - k;
	
	bool f = false;
	memset(btab, 0, sizeof(btab));
	
	for(int i = 0; i < n && !f; ++i) {
		for(int j = 0; j < m && !f; ++j) {
			if(tab[i][j] == '.') {
				dfs(i, j);
				f = true;
			}
		}
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(tab[i][j] == '.') {
				if(!(st.count({i, j}))) tab[i][j] = 'X';
			}
		}
	}
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << tab[i][j];
		} cout << endl;
	}
	return 0;
}
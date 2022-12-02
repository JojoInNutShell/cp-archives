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
vector<int> quadlist;
int board[406][406];
int n;

bool isValid(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) return true;
	else return false;
}

void precompute() {
	for(int i = 0; i <= 1000; ++i) quadlist.pb(i*i);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	precompute();
	int m;
	cin >> n >> m;
	vector<ii> P;
	for(int i = 0; i < 1001; ++i) {
		if(quadlist[i] > m) break;
		if(binary_search(all(quadlist), m - quadlist[i])) {
			P.pb({sqrt(quadlist[i]), sqrt(m - quadlist[i])});
		}
	}
	memset(board, -1, sizeof(board));
	queue<pair<ii, int>> q;
	q.push({{0,0}, 0});
	int x, y;
	int k, l;
	while(!q.empty()) {
		auto pa = q.front(); q.pop();
		x = pa.fi.fi;
		y = pa.fi.se;
		board[x][y] = pa.se;
		for(auto p : P) {
			k = p.fi, l = p.se;
			if(isValid(x + k, y + l) && board[x + k][y + l] == -1) {
				q.push({{x + k, y + l}, pa.se + 1});
				board[x + k][y + l] = pa.se + 1;
			}
			if(isValid(x - k, y + l) && board[x - k][y + l] == -1) {
				q.push({{x - k, y + l}, pa.se + 1});
				board[x - k][y + l] = pa.se + 1;
			}
			if(isValid(x + k, y - l) && board[x + k][y - l] == -1) {
				q.push({{x + k, y - l}, pa.se + 1});
				board[x + k][y - l] = pa.se + 1;
			}
			if(isValid(x - k, y - l) && board[x - k][y - l] == -1) {
				q.push({{x - k, y - l}, pa.se + 1});
				board[x - k][y - l] = pa.se + 1;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
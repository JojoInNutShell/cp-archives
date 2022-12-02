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
string board[1007];
int tab[1007][1007];

int mvx[8] = {-1,-1,-1,0,0,1,1,1};
int mvy[8] = {-1,0,1,-1,1,-1,0,1}; 

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
		for(int i = 0; i < n; ++i) cin >> board[i];
		
		int sx, sy, fx, fy;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(board[i][j] == 'S') {
					sx = i; sy = j;
				} else if(board[i][j] == 'F') {
					fx = i; fy = j;
				}
				if(board[i][j] == 'X') tab[i][j] = -1;
				else tab[i][j] = INF;
			}
		}
		
		queue<ii> q;
		tab[sx][sy] = 0;
		q.push({sx, sy});
		while(!q.empty()) {
			int sz = sza(q);
			while(sz--) {
				ii p = q.front(); q.pop();
			
				for(int i = 0; i < 8; ++i) {
					int curx = p.fi, cury = p.se;
					while(isValid(curx + mvx[i], cury + mvy[i]) && tab[curx + mvx[i]][cury + mvy[i]] != -1 && tab[curx + mvx[i]][cury + mvy[i]] > tab[p.fi][p.se]) {
						//cerr << p.fi << " " << p.se << " " << curx + mvx[i] << " " << cury + mvy[i] << endl;
						if(tab[curx + mvx[i]][cury + mvy[i]] > tab[p.fi][p.se] + 1) {
							tab[curx + mvx[i]][cury + mvy[i]] = tab[p.fi][p.se] + 1;
							q.push({curx + mvx[i], cury + mvy[i]});
						}
						
						curx += mvx[i];
						cury += mvy[i];
					}
				}
			}
		}
		
		if(tab[fx][fy] == INF) {
			cout << -1 << endl;
		} else {
			cout << tab[fx][fy] << endl;
		}
	}
	return 0;
}
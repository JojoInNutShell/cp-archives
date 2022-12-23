/*
	Author: MikiMiku

	Idea: 
		Just a variant to 0/1 BFS.
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
int tab[1007][1007];
int cost[1007][1007];
vector<int> mvx({-1, -1, 0, 1, 1, 1,0, -1});
vector<int> mvy({0, 1, 1, 1, 0, -1, -1, -1});
int r, c;

bool isValid(int i, int j) {
	if(0 <= i && i < r && 0 <= j && j < c) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> r >> c;
	
	for(int i = 0; i < r; ++i) {
		string t;
		cin >> t;
		for(int j = 0; j < c; ++j) tab[i][j] = t[j] - '0';
	}
	
	int q;
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int rs, cs, rd, cd;
		cin >> rs >> cs >> rd >> cd;
		rs--; cs--; rd--; cd--;
		
		for(int i = 0; i < r; ++i) {
			for(int j = 0; j < c; ++j) cost[i][j] = INF;
		}
		
		deque<ii> dq;
		dq.push_back({rs, cs});
		cost[rs][cs] = 0;
		
		while(!dq.empty()) {
			ii p = dq.front(); dq.pop_front();
			int rc = p.fi, cc = p.se;
			
			if(p.fi == rd && p.se == cd) break;
			
			for(int i = 0; i < 8; ++i) {
				if(i == tab[rc][cc]) {
					if(isValid(rc + mvx[i], cc + mvy[i]) && cost[rc][cc] < cost[rc + mvx[i]][cc + mvy[i]]) {
						dq.push_front({rc + mvx[i], cc + mvy[i]});
						cost[rc + mvx[i]][cc + mvy[i]] = cost[rc][cc];
					}
				} else {
					if(isValid(rc + mvx[i], cc + mvy[i]) && cost[rc][cc] + 1 < cost[rc + mvx[i]][cc + mvy[i]]) {
						dq.push_back({rc + mvx[i], cc + mvy[i]});
						cost[rc + mvx[i]][cc + mvy[i]] = cost[rc][cc] + 1;
					}
				}
			}
		}
		
		cout << cost[rd][cd] << endl;
	}
	
	return 0;
}
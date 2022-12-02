#include <bits/stdc++.h>
using namespace std;

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
int r, c;

bool isValid(int i, int j) {
	if(0 <= i && i < r && 0 <= j && j < c) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int quee, irr, inum, cr;
	while(cin >> r >> c) {
		if(r == 0 && c == 0) break;
		vector<vector<int>> land;
		land.assign(r, {});
		for(auto& a : land) a.assign(c, -2);
		cin >> quee;
		
		for(int i = 0; i < quee; ++i) {
			cin >> irr >> inum;
			for(int j = 0; j < inum; ++j) {
				cin >> cr;
				land[irr][cr] = -1;
			}
		}
		int sr, sc, tr, tc;
		queue<pair<int, int>> q;
		cin >> sr >> sc >> tr >> tc;
		q.push(mp(sr, sc)); land[sr][sc] = 0;
		while(!q.empty()) {
			ii p = q.front(); q.pop();
			if(p.fi == tr && p.se == tc) {
				cout << land[tr][tc] << endl;
				break;
			}
			if(isValid(p.fi - 1, p.se) && land[p.fi - 1][p.se] != -1 && land[p.fi - 1][p.se] == -2) {
				q.push(mp(p.fi - 1, p.se));
				land[p.fi - 1][p.se] = land[p.fi][p.se] + 1;
			}
			if(isValid(p.fi + 1, p.se) && land[p.fi + 1][p.se] != -1 && land[p.fi + 1][p.se] == -2) {
				q.push(mp(p.fi + 1, p.se));
				land[p.fi + 1][p.se] = land[p.fi][p.se] + 1;
			}
			if(isValid(p.fi, p.se - 1) && land[p.fi][p.se - 1] != -1 && land[p.fi][p.se - 1] == -2) {
				q.push(mp(p.fi, p.se - 1));
				land[p.fi][p.se - 1] = land[p.fi][p.se] + 1;
			}
			if(isValid(p.fi, p.se + 1) && land[p.fi][p.se + 1] != -1 && land[p.fi][p.se + 1] == -2) {
				q.push(mp(p.fi, p.se + 1));
				land[p.fi][p.se + 1] = land[p.fi][p.se] + 1;
			}
		}
	}
	return 0;
}
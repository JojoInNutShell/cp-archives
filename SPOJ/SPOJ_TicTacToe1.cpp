#include <bits/stdc++.h>
using namespace std;

//#define int long long
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
bool isWin(string cur) {
	bool row =	
		(cur[0] == cur[1] && cur[1] == cur[2] && cur[0] != '.') ||
		(cur[3] == cur[4] && cur[4] == cur[5] && cur[3] != '.') ||
		(cur[6] == cur[7] && cur[7] == cur[8] && cur[6] != '.');
	bool col =	
		(cur[0] == cur[3] && cur[3] == cur[6] && cur[0] != '.') ||
		(cur[1] == cur[4] && cur[4] == cur[7] && cur[1] != '.') ||
		(cur[2] == cur[5] && cur[5] == cur[8] && cur[2] != '.');
	bool diag =	
		(cur[0] == cur[4] && cur[4] == cur[8] && cur[0] != '.') ||
		(cur[2] == cur[4] && cur[4] == cur[6] && cur[2] != '.');
		
	return row || col || diag;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		string board = "", start = ".........", s;
		for(int i = 0; i < 3; ++i) {
			cin >> s;
			board += s;
		}
		queue<pair<string, bool>> q;
		q.push(mp(start, 1)); //1 = X 0 = O
		string ans = "no";
		while(!q.empty()) {
			bool cur_play = q.front().se;
			string state = q.front().fi;
			q.pop();
			if(state == board) {
				ans = "yes";
				break;
			}
			if(isWin(state)) continue;
			for(int i = 0; i < 9; ++i) {
				if(state[i] == '.') {
					state[i] = (cur_play ? 'X' : 'O');
					if(state[i] == board[i]) {
						q.push(mp(state,1 ^ cur_play));
					}
					state[i] = '.';
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
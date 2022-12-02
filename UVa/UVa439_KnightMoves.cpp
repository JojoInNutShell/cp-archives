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
array<array<int, 10>, 10> board;

void init() {
	for(auto& a : board) a.fill(-1);
}

bool isValid(int r, int c) {
	if(1 <= r && r <= 8 && 1 <= c && c <= 8) return true;
	else return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s1, s2;
	while(cin >> s1 >> s2) {
		init();
		int rs,cs,rt,ct;
		cs = (s1[0] - 'a') + 1; ct = (s2[0] - 'a') + 1;
		rs = stoi(s1.substr(1,1)); rt = stoi(s2.substr(1,1));
		queue<pair<int, pair<int, int>>> q;
		q.push({0, {rs, cs}}); board[rs][cs] = 0;
		int dist;
		while(!q.empty()) {
			int di = q.front().first;
			int r = q.front().se.fi, c = q.front().se.se;
			q.pop();
			if(r == rt && c == ct) {
				dist = di;
				break;
			}
			if(isValid(r - 1, c - 2) && board[r - 1][c - 2] == -1) {
				board[r - 1][c - 2] = di + 1;
				q.push({di + 1, {r - 1, c - 2}});
			}
			if(isValid(r - 2, c - 1) && board[r - 2][c - 1] == -1) {
				board[r - 2][c - 1] = di + 1;
				q.push({di + 1, {r - 2, c - 1}});
			}
			if(isValid(r - 2, c + 1) && board[r - 2][c + 1] == -1) {
				board[r - 2][c + 1] = di + 1;
				q.push({di + 1, {r - 2, c + 1}});
			}
			if(isValid(r - 1, c + 2) && board[r - 1][c + 2] == -1) {
				board[r - 1][c + 2] = di + 1;
				q.push({di + 1, {r - 1, c + 2}});
			}
			if(isValid(r + 2, c + 1) && board[r + 2][c + 1]  == -1) {
				board[r + 2][c + 1] = di + 1;
				q.push({di + 1, {r + 2, c + 1}});
			}
			if(isValid(r + 1, c + 2) && board[r + 1][c + 2] == -1) {
				board[r + 1][c + 2] = di + 1;
				q.push({di + 1, {r + 1, c + 2}});
			}
			if(isValid(r + 2, c - 1) && board[r + 2][c - 1] == -1) {
				board[r + 2][c - 1] = di + 1;
				q.push({di + 1, {r + 2, c - 1}});
			}
			if(isValid(r + 1, c - 2) && board[r + 1][c - 2] == -1) {
				board[r + 1][c - 2] = di + 1;
				q.push({di + 1, {r + 1, c - 2}});
			}
		}
		cout << "To get from " << s1 << " to " << s2 << " takes " << dist << " knight moves." << endl;
	}
	return 0;
}
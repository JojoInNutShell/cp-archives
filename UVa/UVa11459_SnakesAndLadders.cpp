#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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
array<short, 1000006> playerPos;
array<short, 101> board;

void init() {
	board.fill(0);
	playerPos.fill(1);
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T, a, b, c, sl1,sl2, dicenum;
	bool gameFinish;
	cin >> T;
	if(T == 0) return 0; //Pencegahan aja
	while(T--) {
		cin >> a >> b >> c;
		init();
		for(int i = 0; i < b; ++i) {
			cin >> sl1 >> sl2;
			board[sl1] = sl2;
		}
		gameFinish = false;
		for(int i = 0; i < c; ++i) {
			cin >> dicenum;
			if(gameFinish) continue;
			while(dicenum--) {
				playerPos[i % a] += 1;
				if(playerPos[i % a] == 100) {
					gameFinish = true;
					break;
				}
			}
			if(board[playerPos[i % a]] != 0) {
				playerPos[i % a] = board[playerPos[i % a]];
			}
			if(playerPos[i % a] == 100) {
				gameFinish = true;
			}
		}
		for(int i = 0; i < a; ++i) {
			cout << "Position of player " << i + 1 << " is " << playerPos[i] << "." << endl;
		}
	}
	return 0;
}
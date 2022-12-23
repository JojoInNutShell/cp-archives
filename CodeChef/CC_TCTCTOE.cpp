/*
	Author: MikiMiku

	Idea: 
		The test case in the very worst case is trying
		our possible board setup. Which is way too
		much to simulate tha game by BFS one by one.
		But this could be handled by precomputing
		all valid state before starting to check
		the test case given.
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
vector<vector<int>> ac({{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}});

bool check(string s) {
	for(int i = 0; i < 9; ++i) {
		if(s[i] == '_') break;
		if(i + 1 == 9) return true;
	}
	for(auto v : ac) {
		if(s[v[0]] == s[v[1]] && s[v[1]] == s[v[2]] && s[v[2]] != '_') {
			return true;
		}
	}
	return false;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	unordered_map<string, int> state;
	
	string st = "_________";
	queue<pair<string, int>> q;
	q.push({st, 0});
	
	while(!q.empty()) {
		string tab = q.front().fi;
		int play = q.front().se;
		q.pop();
		if(check(tab)) {
			state[tab] = 1;
			continue;
		} else state[tab] = 2;
		
		for(int i = 0; i < 9; ++i) {
			if(tab[i] == '_') {
				char xo;
				if(play == 0) xo = 'X';
				else xo = 'O';
				
				tab[i] = xo;
				q.push({tab, play^1});
				tab[i] = '_';
			}
		}
	}
	
	int T;
	cin >> T;
	while(T--) {
		string l1, l2, l3;
		cin >> l1 >> l2 >> l3;
		string board = l1 + l2 + l3;
		if(state.count(board)) {
			cout << state[board] << endl;
		} else cout << 3 << endl;
	}
	return 0;
}
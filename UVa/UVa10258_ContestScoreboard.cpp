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

bool cmp(pair<int, pair<int, int>> p1, pair<int, ii> p2) {
	if(p1.fi == p2.fi) {
		if(p1.se.fi == p2.se.fi) {
			return p1.se.se < p2.se.se; 
		} else {
			return p1.se.fi < p2.se.fi;
		}
	} else {
		return p1.fi > p2.fi;
	}
}
signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	
	string gb;
	getline(cin, gb);
	getline(cin, gb);
	
	bool ft = true;
	
	while(T--) {
		if(ft) ft = false;
		else cout << endl;
		
		array<set<int>, 107> solved;
		set<int> parti;
		array<pair<int, pair<int, int>>, 107> data;
		array<array<int, 17>, 107> pn;
		
		for(auto& a : pn) a.fill(0);
		for(int i = 0; i <= 100; ++i) {
			data[i].fi = 0;
			data[i].se.fi = 0;
			data[i].se.se = i;
		}
		
		string ln;
		while(getline(cin, ln)) {
			if(ln == "") break;
			stringstream ss(ln);
			
			int no, task_no, tm;
			char state;
			ss >> no >> task_no >> tm >> state;
			
			if(state == 'I') {
				pn[no][task_no]++;
			} else if(state == 'C') {
				if(solved[no].find(task_no) == solved[no].end()) {
					data[no].fi++;
					data[no].se.fi += pn[no][task_no] * 20 + tm;
					solved[no].insert(task_no);
				}
			}
			parti.insert(no);
		}
		
		vector<pair<int, ii>> board;
		for(auto i : parti) {
			board.pb(data[i]);
		}
		
		sort(all(board), cmp);
		
		int sz = sza(board);
		for(int i = 0; i < sz; ++i) {
			cout << board[i].se.se << " " << board[i].fi << " " << board[i].se.fi << endl;
		}
	}
	return 0;
}
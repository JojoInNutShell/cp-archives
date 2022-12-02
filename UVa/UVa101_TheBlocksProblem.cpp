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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	
	vector<vector<int>> st(n);
	vector<int> pos(n);
	for(int i = 0; i < n; ++i) st[i].pb(i), pos[i] = i;
	
	string s1, s2;
	int a, b;
	while(cin >> s1 >> a >> s2 >> b) {
		if(s1 == "quit") break;
		
		//cerr << s1 << " " << a << " " << s2 << " " << b << endl;
		
		if(a == b || a >= n || b >= n || pos[a] == pos[b]) continue;
		
		if(s1 == "move") {
			if(s2 == "onto") {
				int posa = pos[a];
				for(int i = sza(st[posa]) - 1; i >= 0; --i) {
					int cur = st[posa][i];
					if(cur == a) break;
					else {
						pos[cur] = cur;
						st[cur].pb(cur);
						if(!st[posa].empty()) st[posa].pop_back();
					}
				}
				
				int posb = pos[b];
				for(int i = sza(st[posb]) - 1; i >= 0; --i) {
					int cur = st[posb][i];
					if(cur == b) break;
					else {
						pos[cur] = cur;
						st[cur].pb(cur);
						if(!st[posb].empty()) st[posb].pop_back();
					}
				}
				
				st[posb].pb(a);
				pos[a] = posb;
				if(!st[posa].empty()) st[posa].pop_back();
			} else {
				int posa = pos[a];
				for(int i = sza(st[posa]) - 1; i >= 0; --i) {
					int cur = st[posa][i];
					if(cur == a) break;
					else {
						pos[cur] = cur;
						st[cur].pb(cur);
						if(!st[posa].empty()) st[posa].pop_back();
					}
				}
				
				
				if(!st[posa].empty()) st[posa].pop_back();
				st[pos[b]].pb(a);
				pos[a] = pos[b];
			}
		} else {
			if(s2 == "onto") {
				int posb = pos[b];
				for(int i = sza(st[posb]) - 1; i >= 0; --i) {
					int cur = st[posb][i];
					if(cur == b) break;
					else {
						pos[cur] = cur;
						st[cur].pb(cur);
						if(!st[posb].empty()) st[posb].pop_back();
					}
				}
				
				vector<int> ast;
				int posa = pos[a];
				for(int i = sza(st[posa]) - 1; i >= 0; --i) {
					int cur = st[posa][i];
					ast.pb(cur);
					pos[cur] = posb;
					if(!st[posa].empty()) st[posa].pop_back();
					if(cur == a) break;
				}
				reverse(all(ast));
				for(auto v : ast) {
					st[posb].pb(v);
				}
			} else {
				vector<int> ast;
				int posa = pos[a];
				for(int i = sza(st[posa]) - 1; i >= 0; --i) {
					int cur = st[posa][i];
					//cerr << cur << endl;
					ast.pb(cur);
					pos[cur] = pos[b];
					if(!st[posa].empty()) st[posa].pop_back();
					if(cur == a) break;
				}
				reverse(all(ast));
				for(auto v : ast) {
					st[pos[b]].pb(v);
				}
			}
		}
		
		
		
		// cerr << s1 << " " << a << " " << s2 << " " << b << endl;
		// for(int i = 0; i < n; ++i) {
			// cerr << i << " ";
		// } cerr << endl;
		// for(int i = 0; i < n; ++i) {
			// cerr << pos[i] << " ";
		// } cerr << endl;
		// for(int i = 0; i < n; ++i) {
			// cerr << i << ": ";
			// for(int j = 0; j < sza(st[i]); ++j) {
				// cerr << st[i][j] << " ";
			// }
			// cerr << endl;
		// } cerr << endl;
	}
	
	for(int i = 0; i < n; ++i) {
		cout << i << ":";
		for(int j = 0; j < sza(st[i]); ++j) {
			cout << " " << st[i][j];
		}
		cout << endl;
	}
	return 0;
}
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
vector<string> dict;
vector<vector<int>> adjList;
vector<bool> visited;
map<string, int> wordnum;
int cntword;

void init() {
	dict.clear();
}

bool isDifOne(string s1, string s2) {
	if(sza(s1) != sza(s2)) return false;
	int difcnt = 0, sz = sza(s1);
	for(int i = 0; i < sz; ++i) {
		if(s1[i] != s2[i]) difcnt++;
	}
	if(difcnt == 1) return true;
	else return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	string word, tmp, qstr;
	cin >> T;
	while(T--) {
		init();
		cntword = 0;
		while(cin >> word) {
			if(word == "*") break;
			wordnum.insert(mp(word, cntword));
			dict.pb(word);
			++cntword;
		}
		adjList.reserve(cntword);
		for(int i = 0; i < cntword; ++i) {
			for(int j = i + 1; j < cntword; ++j) {
				if(isDifOne(dict[i], dict[j])) {
					adjList[i].pb(j);
					adjList[j].pb(i);
				}
			}
		}
		getline(cin, tmp);
		string line;
		while(getline(cin, line) && line != "") {
			string qs1, qs2;
			stringstream ss(line);
			ss >> qs1 >> qs2;
			queue<pair<int, int>> q; 
			visited.assign(cntword, false);
			
			pair<string, int> pid, pto;
			pid = *(wordnum.find(qs1));
			pto = *(wordnum.find(qs2));
			
			q.push(mp(pid.se, 0)); visited[pid.se] = true;
			
			while(!q.empty()) {
				ii u = q.front(); q.pop();
				if(u.fi == pto.se) {
					cout << qs1 << " " << qs2 << " " << u.se << endl;
					break;
				}
				for(auto v : adjList[u.fi]) {
					if(visited[v] == false) {
						visited[v] = true;
						q.push(mp(v, u.se + 1));
					}
				}
			}
		}
		if(T != 0) cout << endl;
	}
	return 0;
}
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
//........................................................................
array<array<char, 106>, 106> adj;
array<array<bool, 106>, 106> visited;
int del,f, n;
bool isAt;

void init() {
	for(auto a : visited) {
		a.fill(false);
	}
}

bool isValid(int i, int j) {
	if(0 <= i && i < n && 0 <= j && j < n) {
		return true;
	}
	return false;
}

void dfs(int i, int j) {
	if(adj[i][j] != '@') {
		isAt = false;
	}
	adj[i][j] = '.';
	if(isValid(i - 1, j) && adj[i - 1][j] != '.') {
		dfs(i - 1, j);
	}
	if(isValid(i + 1, j) && adj[i + 1][j] != '.') {
		dfs(i + 1, j);
	}
	if(isValid(i, j - 1) && adj[i][j - 1] != '.') {
		dfs(i, j - 1);
	}
	if(isValid(i, j + 1) && adj[i][j + 1] != '.') {
		dfs(i, j + 1);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	string s;
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		init();
		del = 0; f = 0;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			for(int j = 0; j < n; ++j) {
				adj[i][j] = s[j];
			}
		}
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(adj[i][j] != '.') {
					isAt = true; ++f;
					dfs(i, j);
					if(isAt) {
						++del;
					}
				}
			}
		}
		cout << "Case " << i << ": " << f - del << endl;
	}
	
	return 0;
}
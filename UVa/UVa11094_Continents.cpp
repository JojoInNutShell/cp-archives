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
array<array<bool, 30>, 30> arr;
int n, m, consz;

void init() {
	for(auto ar : arr) {
		ar.fill(false);
	}
}

int verifyn(int x) {
	if(x < 0) {
		return n - 1;
	} else if(x > n - 1) {
		return 0;
	} else {
		return x;
	}
}

bool verifym(int y) {
	if(y < 0 || y > m - 1) {
		return false;
	} else {
		return true;
	}
}

void dfs(int u, int v) {
	int x, y;
	arr[u][v] = false; ++consz;
	x = u - 1; y = verifyn(v);
	if(verifym(x) && arr[x][y] == true) {
		dfs(x, y);
	}
	x = u + 1; y = verifyn(v);
	if(verifym(x) && arr[x][y] == true) {
		dfs(x, y);
	}
	x = u; y = verifyn(v + 1);
	if(verifym(x) && arr[x][y] == true) {
		dfs(x, y);
	}
	x = u; y = verifyn(v - 1);
	if(verifym(x) && arr[x][y] == true) {
		dfs(x, y);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int posm, posn, high;
	string s;
	char land;
	while(cin >> m >> n) {
		array<array<char, 30>, 30> stringsv;
		init();
		for(int i = 0; i < m; ++i) {
			cin >> s;
			transform(s.begin(), s.end(), s.begin(), ::tolower); //Anticipating Cases
			for(int j = 0; j < n; ++j) {
				stringsv[i][j] = s[j];
			}
		}
		cin >> posm >> posn;
		land = stringsv[posm][posn];
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if(stringsv[i][j] == land) {
					arr[i][j] = true;
				} else {
					arr[i][j] = false;
				}
			}
		}
		dfs(posm, posn);
		high = 0;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				consz = 0;
				if(arr[i][j] == true) {
					dfs(i, j);
				}
				if(consz > high) {
					high = consz;
				}
			}
		}
		cout << high << endl;
	}
	
	return 0;
}
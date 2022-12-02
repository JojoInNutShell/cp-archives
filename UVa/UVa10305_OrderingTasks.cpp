#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; i++) 
#define FOR(i,a,b) for(int i = a; i < b; i++) 
#define REPD(i,n) for(int i = n-1; i >= 0; i--) 
#define FORD(i,a,b) for(int i = a; i >= b; i--)

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, u, v, current;
	while(cin >> n >> m) {
		queue<int> q;
		array<bool, 107> visited; visited.fill(false);
		array<vi, 107> adj;
		array<int, 107> deg; deg.fill(0);
		
		if(n == 0 && m == 0) {
			return 0;
		}
		REP(i,m) {
			cin >> u >> v;
			adj[u].push_back(v);
		}
		FOR(i,1,n + 1) { //Initiating degree array
			for(auto val : adj[i]) {
				deg[val] += 1;
			}
		}
		FOR(i,1,n + 1) { //EVERY VERTEX DEGREE 0
			if(deg[i] == 0 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
		while(!q.empty()) {
			current = q.front(); q.pop();
			cout << current << " ";
			visited[current] = true;
			for(auto v : adj[current]) {
				deg[v] -= 1;
			}
			for(int i = 1; i <= n; ++i) {
				if(deg[i] == 0 && visited[i] != true) {
					q.push(i);
					visited[i] = true;
				}
			}
			
		}
		cout << endl;
	}
	
	return 0;
}
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


int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, m, c, nums1, nums2, cur, cases = 1;
	string s, temps, s1, s2, res;
	while(cin >> n) {
		c = 0;
		map<string, int> strint;
		map<int, string> intstr;
		array<vector<int>, 106> adj;
		array<bool, 106> visited; visited.fill(false);
		array<int, 106> deg; deg.fill(0);
		queue<int> bfslist;
		set<int> q;
		
		for(int i = 0; i < n; ++i) { //MAKING CORRESPONDENCE
			cin >> temps;
			strint.insert(make_pair(temps, c));
			intstr.insert(make_pair(c, temps));
			++c;
		}
		cin >> m;
		for(int i = 0; i < m; ++i) { //MAKING ADJ LIST AND DEG LIST
			cin >> s1 >> s2;
			nums1 = (*(strint.find(s1))).se;
			nums2 = (*(strint.find(s2))).se;
			adj[nums1].pb(nums2);
			deg[nums2] += 1;
		}
		for(int i = 0; i < n; ++i) {
			if(deg[i] == 0) {
				q.insert(i);
				visited[i] = true;
			}
		}
		while(!q.empty()) {
			cur = *(q.begin()); q.erase(cur);
			bfslist.push(cur);
			for(auto v : adj[cur]) {
				deg[v] -= 1;
			}
			for(int i = 0; i < n; ++i) {
				if(deg[i] == 0 && visited[i] == false) {
					q.insert(i);
					visited[i] = true;
				}
			}
		}
		cout << "Case #" << cases << ": Dilbert should drink beverages in this order:"; ++cases;
		while(!bfslist.empty()) {
			cur = bfslist.front(); bfslist.pop();
			res = (*(intstr.find(cur))).se;
			cout << " " << res;
		}
		cout << "." << endl << endl;
	}
	
	return 0;
}
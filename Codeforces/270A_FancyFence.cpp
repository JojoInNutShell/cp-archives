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
	int T, c = 362;
	set<int> ans;
	int d = 180, side = 3, a;
	while(c--) { //PRECOMPUTE
		if(d % side == 0) {
			ans.insert(d/side);
		}
		d += 180; side += 1;
	}
	cin >> T;
	while(T--) {
		cin >> a;
		if(ans.find(a) != ans.end()) {
			cout << "YES";
		} else {
			cout << "NO";
		} cout << endl;
		
	}
	
	return 0;
}
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

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................
//1 5 10 25 50
array<ll,12> centcores = {0,1,2,2,2,3,3,3,3,3,4};
array<ll,5> cent = {1,5,10,25,50};
array<array<ll, 30006>, 5> memo;

void init() {
	for(auto& a : memo) {
		for(auto& val : a) {
			val = 0;
		}
	}
}

ll dp(ll m, ll lim) {
	ll limtab;
	limtab = centcores[lim/5];
	if(memo[limtab][m] != 0) {
		return memo[limtab][m];
	}
	if(m < 5 || limtab == 0) {
		memo[limtab][m] = 1;
		return 1;
	} else {
		ll sum = 0;
		for(auto c : cent) {
			if(c <= lim && m >= c) {
				sum += dp(m - c, c);
			}
		}
		memo[limtab][m] = sum;
		return sum;
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	ll n, res;
	while(cin >> n) {
		init();
		res = dp(n,50);
		if(res == 1) {
			cout << "There is only 1 way to produce "  << n <<  " cents change.";
		} else {
			cout << "There are " << res << " ways to produce "  << n <<  " cents change.";
		} cout << endl;
	}
	
	return 0;
}
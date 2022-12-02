#include<bits/stdc++.h>
using namespace std;

//#define int long long
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

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................
map<pair<int, int>, bool> tab;

void dfs(int x, int y) {
	tab[{x, y}] = 0;
	if(tab[{x - 1, y - 1}]) {
		dfs(x - 1, y - 1);
	} 
	if(tab[{x - 1, y}]) {
		dfs(x - 1, y);
	} 
	if(tab[{x, y - 1}]) {
		dfs(x, y - 1);
	} 
	if(tab[{x, y + 1}]) {
		dfs(x, y + 1);
	} 
	if(tab[{x + 1, y}]) {
		dfs(x + 1, y);
	} 
	if(tab[{x + 1, y + 1}]) {
		dfs(x + 1, y + 1);
	} 
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	int a, b;
	for(int i = 0; i < n; ++i) {
		cin >> a >> b;
		tab.insert({{a, b}, 1});
	}
	int ans = 0;
	for(auto p : tab) {
		if(p.se) {
			dfs(p.fi.fi, p.fi.se);
			ans++;
		}
	}
	cout << ans;
	return 0;
}
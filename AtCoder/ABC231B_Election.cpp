#include<iostream>
#include<map>
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

#define fi first
#define se second

//FLOAT PRECISION SETTINGS
/*
cout.setf(ios::fixed,ios::floatfield);
cout.precision(3);
*/
//........................................................................

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	string s;
	cin >> n;
	map<string, int> mp;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		mp[s]++;
	}
	int hi = 0; string nm;
	for(auto p : mp) {
		if(p.second > hi) {
			hi = p.second;
			nm = p.first;
		}
	}
	cout << nm;
	return 0;
}
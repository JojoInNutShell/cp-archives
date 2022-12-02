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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s;
	cin >> s;
	int ans = stoi(s);
	for(int i = 0; i < 2; ++i) {
		rotate(s.begin(), s.begin() + 1, s.end());
		ans += stoi(s);
	}
	cout << ans;
	return 0;
}
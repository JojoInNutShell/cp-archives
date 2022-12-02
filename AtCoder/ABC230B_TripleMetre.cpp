#include<bits/stdc++.h>
#include<cmath>
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
	for(string T : {"oxx", "xxo", "xox"}) {
		bool ok = true;
		for(int i = 0; i < (int)s.size(); ++i) {
			if(T[i % 3] != s[i]) ok = false;
		}
		if(ok) {
			cout << "Yes";
			exit(0);
		}
	}
	cout << "No";
	return 0;
}
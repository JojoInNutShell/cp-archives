#include<iostream>
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

int modneg(int n) {
	n %= 26;
	if(n < 0) {
		return n + 26;
	} else {
		return n;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s, t;
	cin >> s >> t;
	bool ok = true;
	int dif = modneg((s[0] - 'a') - (t[0] - 'a'));
	for(int i = 1; i < (int)s.size(); ++i) {
		if(dif != modneg((s[i] - 'a') - (t[i] - 'a'))) ok = false;
	}
	if(ok) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	return 0;
}
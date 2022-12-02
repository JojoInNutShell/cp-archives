#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

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
vector<int> a;

long long Pow(long long x, long long y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int x;
	while(cin >> x) {
		string cli, tmp;
		getline(cin, tmp);
		getline(cin, cli);
		stringstream ss(cli); int t; a.clear();
		while(ss >> t) a.pb(t); 
		reverse(a.begin(), a.end());
		int sum = 0, sz = a.size();
		for(int i = 1; i < sz; ++i) {
			sum += a[i]*(i)*Pow(x, i - 1);
		}
		cout << sum << endl;
	}
	return 0;
}
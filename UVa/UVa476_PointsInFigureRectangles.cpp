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

map<pair<pair<double, double>, pair<double, double>>, int> arr; //Mapping : x1, x2, y1, y2

bool isValid(double x1, double x2, double y1, double y2, double mx, double yx) {
	if(x1 < mx && mx < x2 && y2 < yx && yx < y1) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	double x1, y1, x2, y2, x3, y3;
	int c;
	char tempch;
	c = 1;
	while(cin >> tempch) {
		if(tempch == '*') {
			break;
		}
		cin >> x1 >> y1 >> x2 >> y2;
		arr.insert(make_pair(make_pair(make_pair(x1, x2),make_pair(y1, y2)),c));
		++c;
	}
	c = 1;
	while(cin >> x3 >> y3) {
		bool isNotContained = true;
		if(x3 == 9999.9 && y3 == 9999.9) {
			break;
		}
		for(auto p : arr) {
			//cout << p.fi.fi.fi << p.fi.fi.se << p.fi.se.fi << p.fi.se.se << x3 << y3 << endl;
			if(isValid(p.fi.fi.fi, p.fi.fi.se, p.fi.se.fi, p.fi.se.se, x3, y3)) {
				cout << "Point " << c << " is contained in figure " << p.se << endl;
				isNotContained = false;
			}
		}
		if(isNotContained) {
			cout << "Point " << c << " is not contained in any figure" << endl;
		}
		++c;
	}
	
	return 0;
}
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

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int T;
	string dmp;
	cin >> T;
	getline(cin, dmp); getline(cin, dmp);
	while(T--) {
		string temps, s;
		multiset<string> strset;
		multimap<string, string> ans;
		while(1) {
			getline(cin, temps);
			if(temps == "") {
				break;
			}
			strset.insert(temps);
		}
		for(auto s1 : strset) {
			for(auto s2 : strset) {
				if(s1 == s2 && strset.count(s1) == 1) continue;
				
				string ss1;
				for(auto c : s1) {
					c = tolower(c);
					if(c != ' ') {
						ss1.pb(c);
					}
				}
				sort(ss1.begin(), ss1.end());
				string ss2;
				for(auto c : s2) {
					c = tolower(c);
					if(c != ' ') {
						ss2.pb(c);
					}
				}
				sort(ss2.begin(), ss2.end());
				if(ss1 == ss2) {
					if(s1 <= s2) {
						if(s1 == s2) {
							auto it = ans.find(s1);
							if(it != ans.end() && (*it).se == s2) continue;
						}
						ans.insert(mp(s1, s2));
					}
				}
			}
		}
		for(auto p : ans) {
			cout << p.fi << " = " << p.se << endl;
		}
		cout << endl;
	}
	return 0;
}
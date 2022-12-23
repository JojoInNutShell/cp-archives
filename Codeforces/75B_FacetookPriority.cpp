/*
	Author: MikiMiku
	
	Observation:
		1. Action not involving "you" don't
		increase priority factor (Cause we just
		want the priority factor between "you" and
		other). But we must be careful because
		this still means that there is this name
		in data even it have a 0 priority factor.
		
	Idea: 
		First, we need to calculate priority factor
		based on data given. After that we sort
		the name in the data with the priority 
		factor between "you". Make custom comparator
		as the sorting priority is a bit different, I guess.
*/

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define eb emplace_back 
#define mp make_pair

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define LSB(S) (S & (-S))
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
//FILE IO
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

//........................................................................

bool comp(pair<int, string> p1, pair<int, string> p2) {
	if(p1.fi == p2.fi) {
		return p1.se < p2.se;
	} else {
		return p1.fi > p2.fi;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string you;
	cin >> you;
	int n;
	cin >> n;
	
	map<string, int> prio;
	for(int i = 0; i < n; ++i) {
		string n1, act;
		cin >> n1 >> act;
		
		string tmp1, n2, tmp2;
		if(act == "posted") {
			cin >> tmp1 >> n2 >> tmp2;
			n2.pop_back(); n2.pop_back();
			
			if(n1 == you) {
				prio[n2] += 15;
			} else if(n2 == you) {
				prio[n1] += 15;
			} else {
				if(!prio.count(n1)) prio[n1] = 0;
				if(!prio.count(n2)) prio[n2] = 0;
			}
		} else if(act == "commented") {
			cin >> tmp1 >> n2 >> tmp2;
			n2.pop_back(); n2.pop_back();
			
			if(n1 == you) {
				prio[n2] += 10;
			} else if(n2 == you) {
				prio[n1] += 10;
			} else {
				if(!prio.count(n1)) prio[n1] = 0;
				if(!prio.count(n2)) prio[n2] = 0;
			}
		} else {
			cin >> n2 >> tmp2;
			n2.pop_back(); n2.pop_back();
			
			if(n1 == you) {
				prio[n2] += 5;
			} else if(n2 == you) {
				prio[n1] += 5;
			} else {
				if(!prio.count(n1)) prio[n1] = 0;
				if(!prio.count(n2)) prio[n2] = 0;
			}
		}
	}
	
	vector<pair<int, string>> a;
	for(auto p : prio) {
		a.eb(p.se, p.fi);
	}
	sort(all(a), comp);
	for(auto p : a) {
		cout << p.se << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

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
array<array<int, 27>, 27> adjMatM, adjMatY;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		for(auto& arr : adjMatM) arr.fill(INF);
		for(auto& arr : adjMatY) arr.fill(INF);
		for(int i = 0; i < 26; ++i) {
			adjMatM[i][i] = 0;
			adjMatY[i][i] = 0;
		}
		
		char age, dir, u, v;
		int w;
		for(int i = 0; i < n; ++i) {
			cin >> age >> dir >> u >> v >> w;
			if(u == v) continue;
			if(age == 'Y') {
				if(dir == 'U') {
					adjMatY[u - 'A'][v - 'A'] = w;
				} else {
					adjMatY[u - 'A'][v - 'A'] = w;
					adjMatY[v - 'A'][u - 'A'] = w;
				}
			} else {
				if(dir == 'U') {
					adjMatM[u - 'A'][v - 'A'] = w;
				} else {
					adjMatM[u - 'A'][v - 'A'] = w;
					adjMatM[v - 'A'][u - 'A'] = w;
				}
			}
		}
		
		for(int k = 0; k < 26; ++k) {
			for(int i = 0; i < 26; ++i) {
				for(int j = 0; j < 26; ++j) {
					adjMatY[i][j] = min(adjMatY[i][j], adjMatY[i][k] + adjMatY[k][j]);
				}
			}
		}
		
		for(int k = 0; k < 26; ++k) {
			for(int i = 0; i < 26; ++i) {
				for(int j = 0; j < 26; ++j) {
					adjMatM[i][j] = min(adjMatM[i][j], adjMatM[i][k] + adjMatM[k][j]);
				}
			}
		}
		
		cin >> u >> v;
		int nu = u - 'A', nv = v - 'A', tmp;
		pair<int, set<char>> ans;
		ans.fi = INF;
		for(int i = 0; i < 26; ++i) {
			tmp = adjMatY[nu][i] + adjMatM[nv][i];
			if(tmp >= INF) continue;
			if(tmp < ans.fi) {
				ans.fi = tmp;
				(ans.se).clear();
				(ans.se).insert(i + 'A');
			} else if(tmp == ans.fi) {
				(ans.se).insert(i + 'A');
			}
		}
		if((ans.se).size() == 0) {
			cout << "You will never meet." << endl;
		} else {
			cout << ans.fi;
			for(auto v : ans.se) {
				cout << " " << v;
			}
			cout << endl;
		}
	}
	return 0;
}
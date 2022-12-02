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
array<vi, 3> adjList;
array<int, 3> deg;
array<bool, 3> vis;

bool detCyc(int u, int c = 0) {
	if(c == 3) return false;
	if((adjList[u]).empty()) return true;
	for(auto v : adjList[u]) {
		return detCyc(v, c + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	string s1, s2, s3;
	int cur;
	queue<int> q; vis.fill(false);
	cin >> s1 >> s2 >> s3;
	if(s1[1] == '<') {
		adjList[s1[0] - 'A'].pb(s1[2] - 'A');
		deg[s1[2] - 'A'] += 1;	
	} else {
		adjList[s1[2] - 'A'].pb(s1[0] - 'A');
		deg[s1[0] - 'A'] += 1;
	}
	if(s2[1] == '<') {
		adjList[s2[0] - 'A'].pb(s2[2] - 'A');	
		deg[s2[2] - 'A'] += 1;	
	} else {
		adjList[s2[2] - 'A'].pb(s2[0] - 'A');
		deg[s2[0] - 'A'] += 1;
	}
	if(s3[1] == '<') {
		adjList[s3[0] - 'A'].pb(s3[2] - 'A');
		deg[s3[2] - 'A'] += 1;		
	} else {
		adjList[s3[2] - 'A'].pb(s3[0] - 'A');
		deg[s3[0] - 'A'] += 1;
	}
	if(deg[0] && deg[1] && deg[2]) {
		cout << "Impossible";
		return 0;
	}
	for(int i = 0; i < 3; ++i) {
		if(deg[i] == 0) {
			q.push(i);
			vis[i] = true;
		}
	}
	while(!(q.empty())) {
		cur = q.front(); q.pop();
		for(auto i : adjList[cur]) {
			deg[i] -= 1;
		}	
		for(int i = 0; i < 3; ++i) {
			if(deg[i] == 0 && vis[i] == false) {
				vis[i] = true;
				q.push(i);
			}
		}
		cout << (char)('A' + cur);
	}
	
	return 0;
}
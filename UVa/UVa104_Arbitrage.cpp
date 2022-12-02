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
double adjMat[26][26][26];
array<array<array<int, 26>, 26>, 26> path;
stack<int> s;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		//cerr << n << endl;
		memset(adjMat, 0, sizeof(adjMat));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				if(i == j) {adjMat[i][j][0] = 1.; path[i][j][0] = i; continue;}
				cin >> adjMat[i][j][0];
				path[i][j][0] = i;
			}
		}
		
		double x;
		for(int l = 1; l < n; ++l) {
			for(int k = 0; k < n; ++k) {
				for(int i = 0; i < n; ++i) {
					for(int j = 0; j < n; ++j) {
						x = adjMat[i][k][l - 1] * adjMat[k][j][0];
						if(x > adjMat[i][j][l]) {
							adjMat[i][j][l] = x;
							path[i][j][l] = k;
						}
					}
				}
			}
		}
		/*
		for(int l = 1; l < n; ++l) {
			for(int i = 0; i < n; ++i) {
				cerr << adjMat[i][i][l] << " ";
			}
			cerr << endl;
		}
		*/
		bool f = false; int temp;
		for(int l = 1; l < n && !f; ++l) {
			for(int i = 0; i < n && !f; ++i) {
				if(adjMat[i][i][l] > 1.01) {
					s.push(path[i][i][l]);
					for(int j = l - 1; j > -1; --j) s.push(path[i][s.top()][j]);
					temp = s.top();
					while(!s.empty()) {
						cout << s.top() + 1 << " ";
						s.pop();
					}
					cout << temp + 1;
					cout << endl;
					f = true;
					break;
				}
			}
		}
		if(!f) {
			cout << "no arbitrage sequence exists" << endl;
		}
	}
	return 0;
}
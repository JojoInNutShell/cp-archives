/*
	Author: MikiMiku

	Idea: 
		We can see this task as a BFS shortest
		path problem variant. Where the variant
		is in its movement. Just implement
		the cursor movement for the BFS as
		described on the statement.
		
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
void setIO() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

//........................................................................
int tab[107][100007];
int n;

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	setIO();
	cin >> n;
	
	int a[107];
	for(int i = 0; i < n; ++i) cin >> a[i];
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	memset(tab, 0, sizeof(tab));
	
	queue<ii> q;
	q.push({r1 - 1, c1 - 1});
	while(!q.empty()) {
		int r = q.front().fi, c = q.front().se; q.pop();
		if(r == r2 - 1 && c == c2 - 1) break;
		
		if(r - 1 >= 0) {
			if(c <= a[r - 1]) {
				if(tab[r - 1][c] == 0) {
					q.push({r - 1, c});
					tab[r - 1][c] = tab[r][c] + 1;
				}
			} else {
				if(tab[r - 1][a[r - 1]] == 0) {
					q.push({r - 1, a[r - 1]});
					tab[r - 1][a[r - 1]] = tab[r][c] + 1;
				}
			}
		}
		if(r + 1 < n) {
			if(c <= a[r + 1]) {
				if(tab[r + 1][c] == 0) {
					q.push({r + 1, c});
					tab[r + 1][c] = tab[r][c] + 1;
				}
			} else {
				if(tab[r + 1][a[r + 1]] == 0) {
					q.push({r + 1, a[r + 1]});
					tab[r + 1][a[r + 1]] = tab[r][c] + 1;
				}
			}
		}
		if(c - 1 >= 0) {
			if(tab[r][c - 1] == 0) {
				q.push({r, c - 1});
				tab[r][c - 1] = tab[r][c] + 1;
			}
		}
		if(c + 1 <= a[r]) {
			if(tab[r][c + 1] == 0) {
				q.push({r, c + 1});
				tab[r][c + 1] = tab[r][c] + 1;
			}
		}
	}
	cout << tab[r2 - 1][c2 - 1] << endl;
	return 0;
}
/*
	Author: MikiMiku
	
	Idea: 
		It's make sense to just use improvement units
		on skills which is nearer to the multiple
		of 10. By the rating system having skill with
		level 37 is the same as level 30. But
		having skill on level 40 is just the same
		as having skill on level 40 (It means we don't
		waste any level later on when converting it
		to ratings).
		
		Here, the implementation is to be greedy with
		the help of priority queue. But an alternative is
		to just calculate first the improvement unit cost
		to make every skill to the nearest multiple of
		10. All the change need to be made must be less
		than or equal to 10, but after the change every
		change later on that will be made must be 10 (or 0).
		
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

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for(int i = 0; i < n; ++i) {
		if(a[i] == 100) continue;
		int up = a[i]/10;
		up++;
		up *= 10;
		
		pq.push({up - a[i], i});
	}
	
	while(!pq.empty() && k) {
		ii cur = pq.top(); pq.pop();
		
		if(k >= cur.fi) {
			a[cur.se] += cur.fi;
			k -= cur.fi;
			
			if(a[cur.se] < 100) {
				int up = a[cur.se]/10;
				up++;
				up *= 10;
				
				pq.push({up - a[cur.se], cur.se});
			}
		} else break;
	}
	
	int rate = 0;
	for(int i = 0; i < n; ++i) {
		rate += (a[i]/10);
	}
	cout << rate << endl;
	return 0;
}
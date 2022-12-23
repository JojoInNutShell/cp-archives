/*
	Author: MikiMiku
	
	Idea: 
		We need to check from day 1 to 366 how
		many male and female available at that day.
		Take the minimum between both (to gurantee
		that later there are as much male as female)
		and multiply that by two will give us how many
		people at that day that could come to the party.
		
		In this implementation to make it faster (we
		don't add the day of male or female available
		one by one) we will use difference array.
		
		Check it here
		https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
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
	int n;
	cin >> n;
	
	int m[400], f[400];
	memset(m, 0, sizeof(m));
	memset(f, 0, sizeof(f));
	
	for(int i = 0; i < n; ++i) {
		char g;
		int a, b;
		cin >> g >> a >> b;
		
		if(g == 'M') {
			m[a]++;
			m[b + 1]--;
		} else {
			f[a]++;
			f[b + 1]--;
		}
	}
	
	int curm = 0, curf = 0;
	int ans = 0;
	for(int i = 1; i <= 366; ++i) {
		curm += m[i];
		curf += f[i];
		
		int res = min(curm, curf);
		res *= 2;
		
		ans = max(ans, res);
	}
	
	cout << ans << endl;
	return 0;
}
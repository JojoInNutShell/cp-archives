/*
	Author: MikiMiku
	
	Observation:
		1. A sorted array a (with element a1, a2, ... an) 
		is good if a1 | a2, a2 | a3, ..., an-1 | an.
		
		(x | y -> x divides y)
		(remember that if x | y and y | z then x | z)
		
		By the transitivity property of divisibility 
		then if that array a follows the above property.
		a must be good.
		
	Idea: 
		To make an array as described in observation 1.
		First, we need to sort the array given. Then,
		after that as out first step we wanted a1 | a2.
		We know that a1 | a2 if a2 % a1 == 0. But
		notice that if a2 % a1 != 0 then we just need to
		apply the operation to add some number to a2
		until a1 % a2 == 0. After that the same thing
		will be applied to a2 and a3, a3 and a4, and so on.
		
		After applying that procedure it is guranteed
		that our array will be good as described in
		observation 1, and the operation needed
		in the procedure will be less than n.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
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
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		
		vector<ii> a(n);
		for(int i = 0; i < n; ++i) {
			cin >> a[i].fi;
			a[i].se = i + 1;
		}
		
		sort(all(a));
		vector<ii> ans;
		for(int i = 1; i < n; ++i) {
			int chg = a[i].fi%a[i - 1].fi;
			chg = a[i - 1].fi - chg;
			a[i].fi += chg;
			ans.pb({a[i].se, chg});
		}
		
		cout << sza(ans) << endl;
		for(int i = 0; i < sza(ans); ++i) {
			cout << ans[i].fi << " " << ans[i].se << endl;
		}
	}
	return 0;
}
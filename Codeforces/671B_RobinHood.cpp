/*
	Author: MikiMiku
	
	Idea: 
		Taking and giving coins is just the same
		as decreement and increement operations.
		We can do this operation separately.
		
		Say we do the increement operation first.
		We may binary search to find what is the
		largest minimum element using at most k
		giving coin operation.
		
		After we find the largest minimum element
		possible (say p). We will change the array according
		to that number, if a[i] < p. Then we will
		change a[i] to p. Else, we don't do anyting.
		But notice that we may still not using all
		the k giving coin (increement) operation.
		So, the operation left that we still could
		do, will be used greedily to increase the
		minimum element at the array.
		
		The same idea will also apply to the taking
		coin (or decreement) operation.
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
	int n, k;
	cin >> n >> k;
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int l = 1, r = 2*INF;
	while(l < r) {
		int mid = (l + r + 1)/2;
		int cost = 0;
		for(int i = 0; i < n; ++i) {
			cost += max(0ll, mid - a[i]);
		}
		if(cost <= k) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	
	int t = k;
	for(int i = 0; i < n; ++i) {
		t -= max(0ll, l - a[i]);
		a[i] = max(a[i], l);
	}
	
	for(int i = 0; i < n; ++i) {
		if(a[i] == l && t) {
			a[i]++;
			t--;
		}
	}
	
	l = 1, r = 2*INF;
	while(l < r) {
		int mid = (l + r)/2;
		int cost = 0;
		for(int i = 0; i < n; ++i) {
			cost += max(a[i] - mid, 0ll);
		}
		if(cost <= k) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	
	t = k;
	for(int i = 0; i < n; ++i) {
		t -= max(0ll, a[i] - l);
		a[i] = min(a[i], l);
	}
	
	for(int i = 0; i < n; ++i) {
		if(a[i] == l && t) {
			a[i]--;
			t--;
		}
	}
	
	int mn = 1e9, mx = 0;
	for(int i = 0; i < n; ++i) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	int ans = mx - mn;
	cout << ans << endl;
	return 0;
}
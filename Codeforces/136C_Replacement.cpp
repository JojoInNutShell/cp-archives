/*
	Author: MikiMiku
		
	Idea: 
		Rather than working on the unsorted version
		of the array, we may sort the array first then
		do some observation on it. Focus on some index
		i, notice that the most minimum number that
		could be on that position is just the number
		beside it, as we change index i to smallest
		number, it will position itself to the
		most front of the array and shifting the
		other element to the right by one.
		
		But watchout on corner case where all element
		in the array is number 1.
		
		Or we could be greedy by just changing the
		largest element in the array to 1 (but don't
		forget the corner case). Then, sort it after that
		we will get the answer which is that array.
		
		Here, we are greedy on moving the smaller
		element to the larger index possible.
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
	
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(all(a));
	
	if(a[n - 1] == 1) a[n - 1] = 2;
	else a[n - 1] = 1;
	sort(all(a));
	
	for(int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	} cout << endl;
	return 0;
}
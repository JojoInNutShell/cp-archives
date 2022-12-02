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
vector<ull> term;

ull mul(int i, int j, int k, int l) {
	ull res = 1;
	for(int m = 0; m < i; ++m) {
		res *= 2;
		if(res > 2000000000) return 0;
	}
	for(int m = 0; m < j; ++m) {
		res *= 3;
		if(res > 2000000000) return 0;
	}
	for(int m = 0; m < k; ++m) {
		res *= 5;
		if(res > 2000000000) return 0;
	}
	for(int m = 0; m < l; ++m) {
		res *= 7;
		if(res > 2000000000) return 0;
	}
	return res;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	//term.pb(0);
	ull temp;
	for(int i = 0; i < 34; ++i) {
		for(int j = 0; j < 34; ++j){
			for(int k = 0; k < 34; ++k) {
				for(int l = 0; l < 34; ++l) {
					temp = mul(i, j, k, l);
					if(temp == 0) continue;
					term.pb(temp);
				}
			}
		}
	}
	sort(term.begin(), term.end());
	int n; //bool ft = true;
	while(cin >> n) {
		if(n == 0) break;
		cout << "The " << n;
		if(n%10 == 1 && (n%100 > 20 || n%100 < 4)) cout << "st";
		else if(n%10 == 2 && (n%100 > 20 || n%100 < 4)) cout << "nd";
		else if(n%10 == 3 && (n%100 > 20 || n%100 < 4)) cout << "rd";
		else cout << "th";
		cout << " humble number is ";
		cout << term[n - 1] << '.' << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define endl '\n'

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
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
	string s;
	while(cin >> s) {
		string f = s;
		string sf;
		
		for(auto c : f) {
			if(c == ']' || c == '[') {
				sf += ' ';
				sf += c;
				sf += ' '; 
			} else sf += c;
		}
		
		vector<string> vs;
		
		stringstream ss(sf);
		string tmp;
		while(ss >> tmp) {
			vs.pb(tmp);
		}
		
		/*
		for(auto i : vs) {
			cerr << i << endl;
		} cerr << endl;
		*/
		
		deque<string> ansdq;
		int sz = sza(vs);
		for(int i = 0; i < sz; ) {
			if(vs[i] == "[") {
				if(i + 1 < sz && vs[i + 1] != "[" && vs[i + 1] != "]") {
					ansdq.push_front(vs[i + 1]);
					i += 2;
				} else i++;
			} else if(vs[i] == "]") {
				if(i + 1 < sz && vs[i + 1] != "[" && vs[i + 1] != "]") {
					ansdq.pb(vs[i + 1]);
					i += 2;
				} else i++;
			} else {
				ansdq.pb(vs[i]);
				i++;
			}
		}
		
		string ans;
		for(auto i : ansdq) {
			ans += i;
		}
		cout << ans << endl;
	}
	return 0;
}
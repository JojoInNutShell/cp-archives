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
	string l1, l2;
	while(getline(cin, l1)) {
		if(l1 == "#") break;
		getline(cin, l2);
		stringstream ss1(l1), ss2(l2);
		
		vector<vector<string>> deck;
		
		string t;
		while(ss1 >> t) deck.pb({t});
		while(ss2 >> t) deck.pb({t});
		//cerr << l1 << " " << l2 << endl;
		
		int i;
		while(1) {
			bool ch = false;
			for(i = 1; i < sza(deck); ++i) {
				string s1 = deck[i - 1].back(), s2 = deck[i].back();
				if(i >= 3) {
					string s3 = deck[i - 3].back();
					if((s2[0] == s3[0]) || (s2[1] == s3[1])) {
						deck[i].pop_back();
						deck[i - 3].pb(s2);
						if(deck[i].empty()) deck.erase(deck.begin() + i);
						ch = true;
						break;
					}
				}
				if((s1[0] == s2[0]) || (s1[1] == s2[1])) {
					deck[i].pop_back();
					deck[i - 1].pb(s2);
					if(deck[i].empty()) deck.erase(deck.begin() + i);
					ch = true;
					break;
				}
			}
			if(!ch) break;
		}
		
		if(sza(deck) == 1) {
			cout << "1 pile remaining: "; 
		} else {
			cout << sza(deck) << " piles remaining: ";
		}
		
		for(int j = 0; j < sza(deck); ++j) {
			if(j) cout << " ";
			cout << sza(deck[j]);
		}
		cout << endl;
	}
	return 0;
}
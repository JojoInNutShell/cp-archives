#include <bits/stdc++.h>
using namespace std;

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back 
#define mp make_pair

#define REP(i,n) for(int i = 0; i < n; ++i) 
#define FOR(i,a,b) for(int i = a; i < b; ++i) 
#define REPD(i,n) for(int i = n-1; i >= 0; --i) 
#define FORD(i,a,b) for(int i = a; i >= b; --i)

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

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int curRound, life;
	string sol, g;
	while(cin >> curRound) {
		if(curRound == -1) return 0;
		cout << "Round " << curRound << endl;
		set<char> solch, wrch, ans;
		bool chicken = true;
		life = 7;
		cin >> sol >> g;
		for(auto c : sol) {
			solch.insert(c);
		}
		for(auto c : g) {
			auto it = solch.find(c);
			if(it == solch.end()) {
				if(ans.find(c) != ans.end()) {
					continue;
				} else {
					if(wrch.find(c) == wrch.end()) {
						wrch.insert(c);
						--life;
						if(life == 0) {
							cout << "You lose." << endl;
							chicken = false;
							break;
						}
					} else {
						continue;
					}
				}
			} else {
				ans.insert(c);
				solch.erase(c);
			}
			if(solch.empty()) {
				cout << "You win." << endl;
				chicken = false;
				break;
			}
		}
		if(chicken) {
			cout << "You chickened out." << endl;
		}
	}
	return 0;
}
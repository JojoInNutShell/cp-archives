#include <bits/stdc++.h>
using namespace std;

#define int long long
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
int n;

int countdif(vector<int>& a1, vector<int>& a2) {
	int dif = 0;
	for(int i = 0, j = 0; i < n && j < n; ) {
		if(a1[i] == a2[j]) {
			i++; j++; dif++;
		} else if(a1[i] < a2[j]) {
			i++;
			//dif++;
		} else {
			j++;
			//dif++;
		}
	}
	return dif;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<int> arr(n);
	int t, M = -INF, m = INF, tot = 0;
	for(int i = 0; i < n; ++i) {
		cin >> t; 
		arr[i] = t;
		
		tot += t;
		M = max(M, t);
		m = min(m, t);
	}
	if(M - m < 2) {
		cout << n << endl;
		for(auto val : arr) {
			cout << val << " ";
		}
		return 0;
	}
	vector<int> avg(n);
	int ag = tot/n, left = tot % n;
	for(int i = n - 1; i >= 0; --i) {
		avg[i] = ag;
		if(left != 0) {
			if(left < 0) {
				avg[i]--;
				left++;
			} else {
				avg[i]++;
				left--;
			}
		}
	}
	sort(all(arr));
	sort(all(avg));
	int avgdif = countdif(arr, avg);
	vector<int> avgidx;
	int det = M - 1;
	for(int i = 0; i < n; ++i) {
		if(avg[i] == det) {
			avgidx.pb(i);
		}
	}
	//cerr << det << endl;
	vector<int> lravg(all(avg));
	for(int i = 1; i < sza(avgidx); i += 2) {
		lravg[avgidx[i - 1]]--;
		lravg[avgidx[i]]++;
	}
	sort(all(lravg));
	int lrdif = countdif(arr, lravg);
	if(lrdif < avgdif) {
		cout << lrdif << endl;
		for(auto val : lravg) {
			cout << val << " ";
		}
	} else {
		cout << avgdif << endl;
		for(auto val : avg) {
			cout << val << " ";
		}
	}
	return 0;
}
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
int arr[206][2], tab[206][206];
//array<array<int, 206>, 206> arr;
//array<array<int, 206>, 2> arr;

int dp(int r, int k) {
	if(tab[r][k] != -1) return tab[r][k];
    if(k == 0) {
        return tab[r][k] = 0;
    }
    if(r == k) {
        int sum0 = 0;
        for(int i = r; i > 0; --i) {
            sum0 += arr[i][0];
        }
        int sum1 = 0;
        for(int i = r; i > 0; --i) {
            sum1 += arr[i][1];
        }
        return tab[r][k] = min(sum0, sum1);
    } else {
        int mn = INF;
        int csum0 = 0;
        for(int i = 1; i <= k; ++i) {
            csum0 += arr[r - (i - 1)][0];
            mn = min(mn, csum0 + dp(r - (i + 1), k - i));
        }
        int csum1 = 0;
        for(int i = 1; i <= k; ++i) {
            csum1 += arr[r - (i - 1)][1];
            mn = min(mn, csum1 + dp(r - (i + 1), k - i));
        }
        mn = min(mn, dp(r - 1, k));
        return tab[r][k] = mn;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
    int n, k;
    while(cin >> n >> k) {
        if(n == 0 && k == 0) break;
       	memset(tab, -1, sizeof(tab));
        int tot = 0;
        for(int i = n; i > 0; --i) {
            cin >> arr[i][0] >> arr[i][1];
            tot += arr[i][0] + arr[i][1];
        }
        cout << tot - dp(n, k) << endl;
    }
    
    return 0;
}
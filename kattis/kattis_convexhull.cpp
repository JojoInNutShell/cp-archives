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
//........................................................................
struct point {
	int x, y;
	point(int _x, int _y) : x(_x), y(_y) {}
	bool operator<(point p) const {
		if(x == p.x) {
			return y < p.y;
		} else {
			return x < p.x;
		}
	}
};

struct vec {
	int x, y;
	vec(int _x, int _y) : x(_x), y(_y) {}
};

point pivot(0,0);

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

vec toVec(point a, point b) {
	return vec(b.x - a.x, b.y - a.y);
}

int cross(vec a, vec b) { return a.x*b.y - a.y*b.x; }

bool collinear(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) == 0;
}

bool angleCmp(point a, point b) {
	if(collinear(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
	int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	while(cin >> n) {
		if(n == 0) break;
		set<point> S;
		int xp, yp;
		for(int i = 0; i < n; ++i) {
			cin >> xp >> yp;
			point tp(xp, yp);
			S.insert(tp);
		}
		vector<point> P;
		for(auto i : S) {
			P.pb(i);
		}
		if(n < 3) {
			//if(!(P[0] == P[n - 1])) P.pb(P[0]);
			cout << sza(P) << endl;
			for(auto p : P) {
				cout << p.x << " " << p.y << endl;
			}
			continue;
		}
		int P0 = 0;
		for(int i = 1; i < n; ++i) {
			if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x)) P0 = i;
		}
		swap(P[0], P[P0]);
		pivot = P[0];
		sort(++P.begin(), P.end(), angleCmp);
		
		vector<point> st;
		st.pb(P[n - 1]); st.pb(P[0]); st.pb(P[1]);
		int i, j;
		i = 2;
		while(i < n) {
			j = (int)st.size() - 1;
			if(ccw(st[j - 1], st[j], P[i])) st.pb(P[i++]);
			else st.pop_back();
		}
		reverse(all(st));
		cout << sza(st) - 1 << endl;
		for(int i = 0; i < sza(st) - 1; ++i) {
			cout << st[i].x << " " << st[i].y << endl;
		}
	}
	return 0;
}
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

struct line { double a, b, c; };
struct point {
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
	point() { x = 0.0; y = 0.0; }
};

void pointToLine(point p1, point p2, line &l) {
	if(fabs(p1.x - p2.x) < EPS) {
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y - p2.y)/(p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

bool isParallel(line l1, line l2) {
	return fabs(l1.b - l2.b) < EPS && fabs(l1.a - l2.a) < EPS;
}

bool isSame(line l1, line l2) {
	return isParallel(l1, l2) && fabs(l1.c - l2.c) < EPS;
}

void intersect(line l1, line l2, point &p) {
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if(fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
}

signed main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	double x1, x2, x3, x4, y1, y2, y3, y4;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(2);
	cout << "INTERSECTING LINES OUTPUT" << endl;
	while(n--) {
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		line l1, l2;
		point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
		pointToLine(p1, p2, l1);
		pointToLine(p3, p4, l2);
		if(isSame(l1, l2)) {
			cout << "LINE" << endl;
		} else if(isParallel(l1, l2)) {
			cout << "NONE" << endl;
		} else {
			point tmp;
			intersect(l1, l2, tmp);
			cout << "POINT " << tmp.x << " " << tmp.y << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

//DATA STRUCTURES SHORTCUT
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

array<array<char, 106>, 106> arr;
string ortlist = "LSONLS";

void printarr(int n, int m) {
	for(int i = 0; i <= n; ++i) {
		for(int j = 0; j <= m; ++j) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

char changeorientation(char current, char instrct) {
	for(int i = 1; i < 5; ++i) {
		if(ortlist[i] == current) {
			if(instrct == 'D') {
				return ortlist[i + 1];
			} else {
				return ortlist[i - 1];
			}
		}
	}
	return current;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, m, sz, c, posx, posy, movx, movy;
	char orient;
	string it, tmp; //Instruction and Mapping
	while(cin >> n >> m >> sz) {
		if(n == 0 && m == 0 && sz == 0) {
			return 0;
		}
		++n; ++m; c = 0;
		for(int i = 0; i <= n; ++i) {
			if(i == 0 || i == n) {
				arr[i].fill('#');
				continue;
			}
			else {
				cin >> tmp;
			}
			for(int j = 0; j <= m; ++j) {
				if(j == 0 || j == m) {
					arr[i][j] = '#';
				} else {
					arr[i][j] = tmp[j - 1];
					if(tmp[j - 1] != '*' && tmp[j - 1] != '#' && tmp[j - 1] != '.') {
						posx = j;
						posy = i;
						orient = tmp[j - 1];
					}
				}
			}
		}
		cin >> it;
		for(auto ins : it) {
			if(ins == 'F') {
				if(orient == 'N') {
					movx = 0; movy = -1;
				} else if(orient == 'S') {
					movx = 0; movy = 1;
				} else if(orient == 'L') {
					movx = 1; movy = 0;
				} else {
					movx = -1; movy = 0;
				}
				
				if(arr[posy + movy][posx + movx] == '#') {
					continue;
				} else {
					posy += movy; posx += movx;
					if(arr[posy][posx] == '*') {
						++c;
						arr[posy][posx] = '.';
					}
				}
			} else {
				orient = changeorientation(orient,ins);
			}
		}
		cout << c << endl;
	}
	
	return 0;
}
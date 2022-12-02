#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int step, m, n, c;
	while(cin >> step >> m){
		if(m == 1) {
			cout << setw(10) << step << setw(10) << m << "    Good Choice" << endl << endl;
			continue;
		}
		n = step; c = 1;
		while(n != 0) {
			n += step;
			n %= m;
			++c;
		}
		
		cout << setw(10) << step << setw(10) << m << "    ";
		if(c == m) {
			cout << "Good Choice";
		} else {
			cout << "Bad Choice";
		} cout << endl << endl;
	}
	return 0;
}
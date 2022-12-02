#include <iostream>
using namespace std;

//........................................................................

int main() {
	ios_base::sync_with_stdio(0);cin.tie(nullptr); cout.tie(nullptr);
	int po, pr, tdo, tdr, curp, curtd;
	bool isP = true;
	cin >> po >> pr >> tdo >> tdr;
	curp = po; curtd = tdo;
	while(curp < curtd) {
		if(isP) {
			curp += pr;
			isP = false;
		} else {
			curtd -= tdr;
			isP = true;
		}
	}
	if(isP) {
		cout << curp;
	} else {
		cout << curtd;
	}
	return 0;
}
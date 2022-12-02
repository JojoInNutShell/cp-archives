#include <bits/stdc++.h>
using namespace std;

array<string, 1001> arr({"","","","010", "1001"});

int main() {
	int high = 4, n, T;
	cin >> T;
	while(T--) {
	    cin >> n;
	    if(n > high) {
	        for(int i = high + 1; i <= n; i++) {
	            if(i % 2 == 0) {
	                arr[i] = arr[i - 2].substr(0, i - 3) + "001";
	            } else {
	                arr[i] = "0" + arr[i - 2] + "0";
	            }
	        }
	        high = n;
	    }
	    cout << arr[n] << endl;
	}
	return 0;
}

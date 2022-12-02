#include<bits/stdc++.h>

using namespace std;

vector<int> coll;

int main() {
    int tc, n, val, e, o;
    bool ans;
    cin >> tc;
    while(tc) {
        cin >> n;
        cin >> e >> o;
        e = e % 2;
        o = o % 2;
        ans = 1;
        if(n == 2) {
            cout << "YES" << endl;
        } else {
            for(int i = 2; i < n; i++) {
                cin >> val;
                if(i % 2 == 0) {
                    if (e == val % 2) {
                        continue;
                    } else {
                        ans = 0;
                    }
                } else {
                    if(o == val % 2) {
                        continue;
                    } else {
                        ans = 0;
                    }
                }
            } 
            if(ans) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        tc--;
    }
}
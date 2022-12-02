#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, s,x,y,z;
    cin >> T;
    while(T--) {
        cin >> s >> x >> y >> z;
        if (x > y) {
            swap(x,y);
        }
        if(x + y + z <= s) {
            cout << 0;
        } else if(x + z <= s) {
            cout << 1;
        } else {
            cout << 2;
        } cout << endl;
    }
}
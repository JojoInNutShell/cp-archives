#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,a,b,c;
    cin >> T;
    while(T--) {
        cin >> a >> b >> c;
        if(a + b + c == 180) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}
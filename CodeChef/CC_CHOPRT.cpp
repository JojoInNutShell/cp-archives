#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        if(n < m) {
            cout << "<";
        } else if(n > m) {
            cout << ">";
        } else {
            cout << "=";
        }
        cout << endl;
    }
    return 0;
}
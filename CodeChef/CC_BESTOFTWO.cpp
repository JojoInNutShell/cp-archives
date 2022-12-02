#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, a, b;
    cin >> T;
    while(T--) {
        cin >> a >> b;
        cout << max(a,b) << endl;
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int p,v,t, n,c;
    c = 0;
    cin >> n;
    while(n--) {
        cin >> p >> v >> t;
        if (p + v + t > 1) {
            ++c;
        }
    }
    cout << c;
    return 0;
}
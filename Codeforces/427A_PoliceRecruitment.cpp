#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, u, k, a;
    string s;
    u = 0; a = 0;
    cin >> n;
    while(n--) {
        cin >> k;
        if(k > 0) {
            a += k;
        } else {
            if(a > 0) {
                --a;
            } else {
                ++u;
            }
        }
    }
    cout << u;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int k, r, c, cur;
    cin >> k >> r;
    c = 1;
    cur = k;
    while(cur % 10 != 0 && (cur - r) % 10 != 0) {
        ++c;
        cur += k;
    }
    cout << c;

    return 0;
}
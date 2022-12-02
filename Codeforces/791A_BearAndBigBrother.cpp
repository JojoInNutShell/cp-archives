#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int a,b,c = 0;
    cin >> a >> b;
    while(a <= b) {
        a *= 3;
        b *= 2;
        ++c;
    }
    cout << c;
    

    return 0;
}
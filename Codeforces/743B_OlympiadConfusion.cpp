#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, c;
    long long k;
    c = 1;
    cin >> n >> k;
    while(k % 2 == 0) {
        k /= 2;
        ++c;
    }
    cout << c;
    return 0;
}
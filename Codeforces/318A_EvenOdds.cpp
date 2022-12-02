#include <bits/stdc++.h>

using namespace std;

int main()
{
    unsigned long long int n, k, o, e;
    cin >> n >> k;
    if(n % 2 == 0) {
        o = n /2;
        e = o;
    } else {
        e = n / 2;
        o = e + 1;
    }
    if(k > o) {
        k = k - o;
        cout << 2*k;
    } else {
        cout << 2*k - 1;
    }

    return 0;
}
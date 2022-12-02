#include <bits/stdc++.h>
using namespace std;
using ll = int;

ll collatz(ll n) {
    if(n == 1) {
        return 1;
    } else {
        if(n % 2 == 0) {
            return collatz(n/2) + 1;
        } else {
            return collatz(3*n + 1) + 1;
        }
    }
}

int main()
{
    ll high, l, r, temp, x, y;
    while(cin >> l >> r) {
        high = 0; x = l; y = r;
        if (l > r) {
            swap(l, r);
        }
        for(ll i = l; i <= r; ++i) {
            high = max(high, collatz(i));
        }
        cout << x << " " << y << " " << high << endl;
    }
}
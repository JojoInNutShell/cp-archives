#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    int y,w, high, num, den, comdiv;
    den = 6;
    cin >> y >> w;
    high = max(y,w);
    num = 6 - high + 1;
    comdiv = gcd(num, den);
    num /= comdiv; den /= comdiv;
    cout << num << "/" << den;
}
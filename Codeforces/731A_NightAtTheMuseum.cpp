#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int sum, r;
    string s;
    char current;
    current = 'a'; sum = 0;
    cin >> s;
    for(auto c : s) {
        r = abs((int)current - (int)c);
        sum += min(r, abs(26 - r));
        current = c;
    }
    cout << sum;
}
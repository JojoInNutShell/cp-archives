#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, c;
    string s;
    c = 0;
    cin >> n;
    cin >> s;
    for(int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ++c;
        }
    }
    cout << c;
}
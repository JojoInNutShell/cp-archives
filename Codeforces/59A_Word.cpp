#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int upper = 0, lower = 0;
    string s;
    cin >> s;
    for(auto c : s) {
        if(c >= 65 && c <= 90) {
            ++upper;
        } else {
            ++lower;
        }
    }
    if (lower >= upper) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    } else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    cout << s;
}
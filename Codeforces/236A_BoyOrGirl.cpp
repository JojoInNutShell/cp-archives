#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    array<bool, 26> charcheck;
    int c = 0;
    string s;
    charcheck.fill(0);
    cin >> s;
    for(auto a : s) {
        charcheck[a - 'a'] = true;
    }
    for(auto b : charcheck) {
        if(b == true) {
            ++c;
        }
    }
    if(c % 2 == 0) {
        cout << "CHAT WITH HER!";
    } else {
        cout << "IGNORE HIM!";
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    string s1, s2;
    int c;
    c = 1;
    cin >> s1 >> s2;
    auto pos1 = s1.begin();
    for(auto val : s2) {
        if(val == *pos1) {
            ++pos1;
            ++c;
        }
    }
    cout << c;
}
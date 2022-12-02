#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, sum = 0;
    string s;
    cin >> T;
    while(T--) {
        sum = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            sum += ((int)s[i] - (int)'0');
        }
        cout << sum << endl;
    }
    return 0;
}
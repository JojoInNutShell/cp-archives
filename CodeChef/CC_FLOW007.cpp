#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        reverse(s.begin(), s.end());
        cout << stoi(s) << endl;
    }
    return 0;
}
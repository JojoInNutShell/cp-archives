#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        cout << ((int)*(s.begin()) - (int)'0') + ((int)*(prev(s.end())) - (int)'0')<< endl;
    }
    return 0;
}
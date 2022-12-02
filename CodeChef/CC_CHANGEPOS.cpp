#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, s1, s2, e1,e2;
    cin >> T;
    while(T--) {
        cin >> s1 >> s2 >> e1 >> e2;
        if(s1 == e1 || s2 == e2) {
            cout << "2";
        } else {
            cout << "1";
        } cout << endl;
    }
}
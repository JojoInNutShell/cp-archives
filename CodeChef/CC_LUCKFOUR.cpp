#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, sum;
    string s;
    cin >> T;
    while(T--) {
        sum = 0;
        cin >> s;
        for(auto c : s) {
            if(c == '4') {
                sum++;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
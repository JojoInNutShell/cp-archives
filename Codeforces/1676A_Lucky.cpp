#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T, num1, num2;
    string s, n1, n2;
    cin >> T;
    while(T--) {
        cin >> s;
        n1 = s.substr(0, 3);
        n2 = s.substr(3);
        num1 = ((int)n1[0] - (int)'0') + ((int)n1[1] - (int)'0') + ((int)n1[2] - (int)'0');
        num2 = ((int)n2[0] - (int)'0') + ((int)n2[1] - (int)'0') + ((int)n2[2] - (int)'0');
        if(num1 == num2) {
            cout << "YES";
        } else {
            cout << "NO";
        } cout << endl;
    }

    return 0;
}
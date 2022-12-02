#include <bits/stdc++.h>

using namespace std;

string arr = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main()
{
    string s;
    while(getline(cin, s)) {
        for(auto& c : s) {
            if(c == ' ') {
                continue;
            }
            auto pos = find(arr.begin(), arr.end(), c);
            c = *(--pos);
        } 
        cout << s << endl;
    }
    
    return 0;
}
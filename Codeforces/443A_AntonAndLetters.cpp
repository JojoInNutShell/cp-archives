#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<char> coll;
    string s;
    getline(cin, s);
    for(auto& c : s) {
        c = ::tolower(c);
        if(c >= 97 && c <= 122) {
            coll.insert(c);
        }
    }
    cout << coll.size();

    return 0;
}
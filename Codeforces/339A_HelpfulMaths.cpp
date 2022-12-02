#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    int n;
    multiset<int> coll;
    while(getline(cin, s, '+')) {
        coll.insert(stoi(s));
    }
    for(auto it = coll.begin(); it != coll.end(); ++it) {
        cout << *it;
        if(next(it) == coll.end()) {
            continue;
        } else {
            cout << "+";
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector<int> coll;

int main()
{
    int n, currentlen = 0;
    while(cin >> n) {
        coll.push_back(n);
        ++currentlen;
        if(currentlen % 2 == 0) {
            nth_element(coll.begin(), coll.begin() + (currentlen / 2),coll.end());
            nth_element(coll.begin(), coll.begin() + (currentlen / 2) - 1,coll.end());
            cout << (coll[currentlen / 2] + coll[(currentlen / 2) - 1]) / 2;
        } else {
            nth_element(coll.begin(), coll.begin() + currentlen / 2,coll.end());
            cout << coll[currentlen / 2];
        } cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    if(a < b) {
        cout << "-1";
    } else if(a == b) {
        cout << "0";
    } else {
        cout << "1";
    }
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, c = 1;
    string sprev, s;
    cin >> n;
    cin >> sprev;
    --n;
    while(n--) {
        cin >> s;
        if(sprev != s) {
            ++c;
        }
        sprev = s;
    }
    cout << c;
}
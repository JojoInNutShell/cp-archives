#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    set<int> arr;
    int temp;
    for(int i = 0; i < 4; ++i) {
        cin >> temp;
        arr.insert(temp);
    }
    cout << 4 - arr.size();
}
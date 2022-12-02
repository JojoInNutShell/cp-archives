#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, c;
    array<int, 104> arr;
    c = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.begin() + n);
    for(int i = 0; i < n; ++i) {
        cout << arr[i];
        if(i + 1 != n) {
            cout << " ";
        }
    }
}
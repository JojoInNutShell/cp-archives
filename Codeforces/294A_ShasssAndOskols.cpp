#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    array<int, 106> arr;
    int n, m, x, y;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> arr[i];
    } 
    cin >> m;
    while(m--) {
        cin >> x >> y;
        arr[x - 1] += y - 1;
        arr[x + 1] += arr[x] - y;
        arr[x] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        cout << arr[i] << endl;
    } 
}
#include <bits/stdc++.h>

using namespace std;

array<int, 1005> arr;

int main()
{
    int T,n,sum, k;
    cin >> T;
    while(T--) {
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> k;
            arr[i] = k;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] <= arr[i]) {
                    sum++;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void printarr(array<int, 3>& arr) {
    cout << arr[1] << " " << arr[2] << " " << arr[0];
}

array<array<int, 3>, 100006> temp;
array<int, 3> arr({1,2,3});

int main()
{
    int T, n, save = 5, num;
    cin >> T;
    while(T--) {
        cin >> n;
        if(n > save) {
            for(int i = save + 1; i <= n; i++) {
                temp[i] = arr;
                num = i % 3;
                num = 2 - num;
                arr[num]++;
            }
            save = n;
        }
        printarr(temp[n]);
        cout << endl;
    }

    return 0;
}

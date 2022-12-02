#include <bits/stdc++.h>

using namespace std;

array<int, 3006> arr;
array<int, 3235> dif;

int main()
{
    bool jolly;
    int n;
    while(cin >> n) {
        jolly = true;
        dif.fill(false);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        for(int i = 1; i < n; ++i) {
            dif[ abs(arr[i] - arr[i - 1]) ] = true;
        }
        for(int i = 1; i < n; ++i) {
            if(!dif[i]) {
                jolly = false;
            }
        }
        if(jolly) {
            cout << "Jolly";
        } else {
            cout << "Not jolly";
        } cout << endl;
    }

    return 0;
}
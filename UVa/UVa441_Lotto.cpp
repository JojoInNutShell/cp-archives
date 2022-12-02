#include <bits/stdc++.h>

using namespace std;

array<int, 20> arr;

int main()
{
    int n,k;
    cin >> n;
    while(n != 0) {
        for(int i = 0; i < n; i++) {
            cin >> k;
            arr[i] = k;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    for(int l = k + 1; l < n; l++) {
                        for(int m = l + 1; m < n; m++) {
                            for(int nn = m + 1; nn < n; nn++) {
                                cout << arr[i] << " " << arr[j] <<  " " << arr[k] << " " << arr[l] << " "<< arr[m] << " " <<arr[nn] << endl;
                            }
                        }
                    }
                }
            }
        }
        cin >> n;
        if(n != 0) {
            cout << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

array<int, 1005> arr;

int main()
{
    long int T,n = -1,q, k, dif, lowdif, cursumlow, c = 1;
    cin >> n;
    while(n != 0) {
        for(int i = 0; i < n; i++) {
            cin >> k;
            arr[i] = k;
        }
        cin >> q;
        cout << "Case " << c << ":" << endl;
        for(int i = 0; i < q; i++) {
            lowdif = 500000000;
            cin >> k;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    dif = abs((arr[i] + arr[j]) - k);
                    if(dif < lowdif) {
                        lowdif = dif;
                        cursumlow = arr[i] + arr[j];
                    }
                }
            }
            cout << "Closest sum to " << k << " is " << cursumlow << "."<< endl;
            
        }
        cin >> n;
        c++;
    }

    return 0;
}
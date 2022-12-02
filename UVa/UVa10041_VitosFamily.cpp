#include <bits/stdc++.h>

using namespace std;

array<int, 30007> arr;

int main()
{
    int T;
    int s, min, sum;
    cin >> T;
    while(T--) {
        sum = 0;
        cin >> s;
        for(int i = 0; i < s; ++i) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.begin() + s);
        min = arr[s/2];
        for(int i = 0; i < s; ++i) {
            sum += (abs(min - arr[i]));
        }
        cout << sum;
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr;
    int T, n, num, lowest, temp, sum;
    string s, n1, n2;
    cin >> T;
    while(T--) {
        arr.clear();
        sum = 0;
        cin >> n;
        
        cin >> num;
        lowest = num;
        arr.push_back(num);
        
        for(int i = 1; i < n; i++) {
            cin >> num;
            arr.push_back(num);
            if(arr[i] < lowest) {
                lowest = arr[i];
            }
        }
        
        for(auto val : arr) {
            sum += val - lowest;
        }
        cout << sum << endl;
    }

    return 0;
}
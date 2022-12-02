#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int arr[5][5], n;
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            cin >> n;
            if(n == 1) {
                cout << abs(i - 2) + abs(j - 2);
            }
        }
    }
}
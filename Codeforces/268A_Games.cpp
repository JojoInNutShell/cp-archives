#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int sum, n;
    array<int, 31> home,guest;
    sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> home[i] >> guest[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }
            if(home[i] == guest[j]) {
                ++sum;
            }
        }
    }
    cout << sum;
}
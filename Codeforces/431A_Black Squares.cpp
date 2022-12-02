#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, sum;
    array<int, 5> arr;
    string s;
    sum = 0;
    cin >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    cin >> s;
    for(auto c : s) {
        n = (int)c - (int)'0';
        sum += arr[n];
    }
    cout << sum;
}
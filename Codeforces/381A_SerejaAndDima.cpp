#include <bits/stdc++.h>

using namespace std;

int s = 0, d = 0;
void sereja(int l, int r, const array<int, 1001>& arr); 
void dima(int l, int r, const array<int, 1001>& arr);

void sereja(int l, int r, const array<int,1001>& arr) {
    if(l == r) {
        s += arr[l];
        return;
    } else {
        if(arr[l] > arr[r]) {
            s += arr[l];
            dima(l + 1, r, arr);
            return;
        } else {
            s += arr[r];
            dima(l, r - 1, arr);
            return;
        }
    }
}

void dima(int l, int r, const array<int, 1001>& arr) {
    if(l == r) {
        d += arr[l];
        return;
    } else {
        if(arr[l] > arr[r]) {
            d += arr[l];
            sereja(l + 1, r, arr);
            return;
        } else {
            d += arr[r];
            sereja(l, r - 1, arr);
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, temp;
    array<int, 1001> arr;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sereja(0, n - 1, arr);
    cout << s << " " << d;
}
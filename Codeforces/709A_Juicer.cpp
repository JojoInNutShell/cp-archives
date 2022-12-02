#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(nullptr); ios_base::sync_with_stdio(false);
    array<int, 100007> arr;
    int n,b,d,tmp, c, tot;
    c = 0; tot = 0;
    cin >> n >> b >> d;
    for(int i = 0; i < n; ++i) { //Input and discard greater than b
        cin >> tmp;
        if(tmp > b) {
            continue;
        } else {
            arr[c] = tmp;
            ++c;
        }
    }
    n = c;
    c = 0;
    for(int i = 0; i < n; ++i) {
        tot += arr[i];
        if (tot > d) {
            tot = 0;
            ++c;
        }
    }
    cout << c;
}
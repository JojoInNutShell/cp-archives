#include <bits/stdc++.h>

using namespace std;

array<int, 50> sol;

int santa(int n, int min = 1) {
    if (n - min < 0) {
        sol[min - 2] += n;
        return min - 1;
    } else {
        sol[min - 1] = min;
        return santa(n - min, min + 1);
    }
}

int main()
{
    int n, k;
    cin >> n;
    k = santa(n);
    cout << k << endl;
    for(int i = 0; i < k; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}
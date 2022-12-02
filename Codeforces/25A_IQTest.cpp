#include <iostream>

using namespace std;

int main()
{
    int n, k, even, odd, cureven, curodd;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> k;
        if(k % 2 == 0) {
            cureven = i;
            even++;
        } else {
            curodd = i;
            odd++;
        }
    }
    if (even == 1) {
        cout << cureven;
    } else {
        cout << curodd;
    }

    return 0;
}
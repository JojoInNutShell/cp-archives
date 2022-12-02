#include <iostream>
#include <array>

using namespace std;

int main()
{
    array<int, 530> a;
    int n, k, d;
    d = 0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0, j = 1; j < n; ++i, ++j) {
        if(a[i] + a[j] >= k) {
            continue;
        } else {
            d += k - (a[i] + a[j]);
            a[j] += k - (a[i] + a[j]);
        }
    }
    cout << d << endl;
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}
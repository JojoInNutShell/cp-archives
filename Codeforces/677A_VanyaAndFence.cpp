#include <iostream>

using namespace std;

int main()
{
    int n, h, sumwidth = 0, k;
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> k;
        if(k > h) {
            sumwidth += 2;
        } else {
            sumwidth += 1;
        }
    }
    cout << sumwidth;

    return 0;
}
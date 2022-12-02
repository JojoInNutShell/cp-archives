#include <iostream>

using namespace std;

int main()
{
    int n, k, num, sum = 0;
    cin >> n >> k;
    while(n--) {
        cin >> num;
        if(num % k == 0) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}
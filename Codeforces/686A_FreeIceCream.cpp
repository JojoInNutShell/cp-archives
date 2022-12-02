#include <iostream>

using namespace std;

int main()
{
    string s;
    char c;
    long long n, x, t, stres;
    stres = 0;
    cin >> n >> x;
    while(n--) {
        cin >> c >> t;
        if(c == '+') {
            x += t;
        } else {
            if(t > x) {
                ++stres;
            } else {
                x -= t;
            }
        }
    }
    cout << x << " " << stres;

    return 0;
}
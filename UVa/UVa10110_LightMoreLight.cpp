#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned long long n;
    while(cin >> n && n != 0) {
        if(floor(sqrt(n)) * floor(sqrt(n)) == n) {
            cout << "yes";
        } else {
            cout << "no";
        } cout << endl;
    }
    return 0;
}
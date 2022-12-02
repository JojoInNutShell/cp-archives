#include <iostream>

using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    while(n--) {
        cin >> s;
        if(s.size() > 10) {
            cout << s.front();
            cout << s.size() - 2;
            cout << s.back();
        } else {
            cout << s;
        } cout << endl;
    }

    return 0;
}
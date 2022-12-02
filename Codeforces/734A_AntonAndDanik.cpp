#include <iostream>

using namespace std;

int main()
{
    int n, A = 0, D = 0;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') {
            A++;
        } else {
            D++;
        }
    }
    if(A == D) {
        cout << "Friendship";
    } else if(A > D) {
        cout << "Anton";
    } else {
        cout << "Danik";
    }
    

    return 0;
}
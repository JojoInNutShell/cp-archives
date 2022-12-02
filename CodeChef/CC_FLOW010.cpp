#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    char c;
    cin >> T;
    while(T--) {
        cin >> c;
        c = tolower(c);
        if(c == 'b') {
            cout << "BattleShip";
        } else if(c == 'c') {
            cout << "Cruiser";
        } else if(c == 'd') {
            cout << "Destroyer";
        } else {
            cout << "Frigate";
        }
        cout << endl;
    }
    return 0;
}
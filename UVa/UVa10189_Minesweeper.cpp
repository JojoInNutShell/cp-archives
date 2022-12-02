#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m, x, y, c, curtest = 1;
    array<array<char, 105>, 105> arr;
    array<array<char, 105>, 105> res;
    while(cin >> n >> m && n != 0 && m != 0) {
        if(curtest > 1) {
            cout << endl;   
        }
        x = n + 2;
        y = m + 2;
        for(int i = 0; i < x; i++) { //Init by input and sentinel adding
            for(int j = 0; j < y; j++) {
                if(i == 0 || j == 0 || i + 1 == x || j + 1 == y) {
                    arr[i][j] = '.';
                } else {
                    cin >> arr[i][j];
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(arr[i][j] == '*') {
                    res[i][j] = '*';
                } else {
                    c = 0; //To count all mine surround
                    for(int k = i - 1; k <= i + 1; ++k) {
                        for(int m = j - 1; m <= j + 1; ++m) {
                            if(arr[k][m] == '*') {
                                ++c;
                            }
                        }
                    }
                    res[i][j] = (c + (int)'0');
                }
            }
        }
        cout << "Field #" << curtest << ":" << endl; ++curtest;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                cout << res[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
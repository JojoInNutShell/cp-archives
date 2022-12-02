/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

array<array<int,110>,110> coll;

int cake(const int& n, const int& m) {
    if(coll[n][m] != 0) {
        return coll[n][m];
    } else {
        if(n == 1) {
            return m - 1;
        } else if(m == 1) {
            return n - 1;
        } else {
            coll[n][m] = n + cake(n, m - 1);
            return coll[n][m];
        }
    }
}

int main()
{
    int testc, n, m, k;
    cin >> testc;
    for(int i = 1; i<= testc; i++) {
        cin >> n >> m >> k;
        if(cake(n, m) == k) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
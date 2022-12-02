/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

string a,b,d,e;
int pos_a, pos_b;
string alpha[56] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
int val_al[56] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28};

int findd(string s) {
    for(int i = 0;i < 53;i++) {
        if (s == alpha[i]) {
            return i % 26;
        }
    } return 0;
}

int compare(string a, string b) {
    d = a[0];
    e = b[0];
    pos_b = findd(e);
    pos_a = findd(d);
    if(a.length() == 0) {
        return 0;
    }
    if (pos_a < pos_b) {
        return -1;
    } else if(pos_a > pos_b) {
        return 1;
    } else {
        return compare(a.substr(1,a.length() - 1), b.substr(1,b.length() - 1));
    }
}

int main()
{
    cin >> a;
    cin >> b;
    cout << compare(a,b);
}

#include <iostream>
#include <array>

using namespace std;

int main()
{
    string n, m;
    array<bool, 14> cr;
    int t, nl, ml, maxl, carry, c;
    while(cin >> n >> m && n != "0" || m != "0") {
        carry = 0; cr.fill(0);
        nl = n.size(); ml = m.size();
        n.push_back('0'); m.push_back('0');
        if(nl > ml) {
            t = nl - ml;
            while(t--) m.insert(m.begin(), '0');
        } else {
            t = ml - nl;
            while(t--) n.insert(n.begin(), '0');
        }
        maxl = max(nl, ml);
        for(int i = maxl - 1; i >= 0; --i) {
            if((n[i + 1] - '0') + (m[i + 1] - '0') + cr[i + 1] > 9) {
                cr[i] = 1;
            } else {
                cr[i] = 0;
            }
            if((n[i] - '0') + (m[i] - '0') + cr[i] > 9) {
                ++carry;
            }
        }
        if(carry > 1) {
            cout << carry << " carry operations.";
        } else if(carry == 1) {
            cout << "1 carry operation.";
        } else {
            cout << "No carry operation.";
        } cout << endl;
    }
    
    
    

    return 0;
}
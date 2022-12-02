#include <bits/stdc++.h>

using namespace std;

multiset<int> b, s;

void PRINT_ARR() {
    cout << "b : ";
    for(auto val : b) {
        cout << val << " ";
    } cout << endl;
    cout << "s : ";
    for(auto val : s) {
        cout << val << " ";
    } cout << endl;
}

int main()
{
    int B, S, c = 1;
    while(cin >> B >> S && B != 0 || S != 0) {
        b.clear(); s.clear();
        int t;
        multiset<int>::iterator cur, mtch;
        for(int i = 0; i < B; ++i) {
            cin >> t;
            b.insert(t);
        }
        for(int i = 0; i < S; ++i) {
            cin >> t;
            s.insert(t);
        }
        while(!b.empty() && !s.empty()) {
            cur = prev(b.end());
            auto pos = s.lower_bound(*cur);
            if(pos == s.end()) {
                mtch = prev(s.end());
            } else if(pos == s.begin()) {
                mtch = s.begin();
            } else {
                if(*cur - *pos > *cur - *(prev(pos))) {
                    mtch = prev(pos);
                } else {
                    mtch = pos;
                }
            }
            b.erase(cur); s.erase(mtch);
        }
        cout << "Case " << c << ": "; ++c;
        if(b.size() == 0) {
            cout << b.size();
        } else {
            cout << b.size() << " " << *b.begin();
        } cout << endl;
    }

    return 0;
}
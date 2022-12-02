#include <bits/stdc++.h>

using namespace std;

int toodd(int n) {
    int c = 0;
    while(n % 2 != 1) {
        ++c;
        n /= 2;
    }
    return c;
}

int main()
{
    int T, n, x, e, o, k, move;
    vector<int> arr;
    multiset<int> low; // pair,key -> to make odd,
    cin >> T;
    while(T--) {
        arr.clear(); low.clear();
        e = 0; o = 0;
        cin >> x;
        n = 2*x;
        for(int i = 0; i < n; ++i) { //Init
            cin >> k;
            if(k % 2 == 0) {
                ++e;
            } else {
                ++o;    
            }
            arr.push_back(k);
        }
        if (e < o) {
            cout << o - x;
        } else if (e > o) {
            for(int i = 0; i < n; ++i) {
                if(arr[i] % 2 == 0) {
                    low.insert(toodd(arr[i]));
                }
            }
            move = 0;
            auto m = low.begin();
            for(auto i = 0; i < e - x; ++i) {
                move += *m;
                ++m;
            }
            cout << move;
        } else {
            cout << 0;
        } cout << endl;
    }
}
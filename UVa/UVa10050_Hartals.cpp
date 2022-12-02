#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T,simd, parpol, d, sum, inc;
    array<int, 3700> days;
    cin >> T;
    while(T--) {
        days.fill(false); sum = 0;
        cin >> simd;
        cin >> parpol;
        for(int i = 0; i < parpol; ++i) {
            cin >> inc;
            d = inc;
            while(d <= simd) {
                if(d % 7 == 6 || d % 7 == 0) {
                    
                } else {
                    if(days[d]) {
                        
                    } else {
                        days[d] = true;
                        ++sum;
                    }
                }
                d += inc;
            }
        }
        cout << sum << endl;
    }

    return 0;
}
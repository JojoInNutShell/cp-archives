#include <bits/stdc++.h>

using namespace std;

int main()
{
    using ll = long long;
    ll T, n, x, y, sum, sumb,k;
    vector<ll> bi, a;
    cin >> T;
    while(T--) {
        bi.clear(); sum = 0; a.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            cin >> k;
            sum += k;
            bi.push_back(k);
        }
        sumb = sum / (n + 1);
        for(ll i = 0; i < n; ++i) {
            a.push_back(bi[i] - sumb);
        }
        for(auto val : a) {
            cout << val << " ";
        } cout << endl;
    }
}
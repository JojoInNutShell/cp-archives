#include <iostream>
#include <set>

using namespace std;

multiset<int> a;

void PRINT_ARR() {
    for(auto val : a) {
        cout << val << " ";
    } cout << endl;
}

int main()
{
    int n, m, t, mx, mn;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        a.insert(t);
    }
    mx = m + *(prev(a.end()));
    for(int i = 0; i < m; ++i) {
        t = *(a.begin());
        a.insert(t + 1);
        a.erase(a.begin());
    }
    mn = *(prev(a.end()));
    cout << mn << " " << mx;
    
    return 0;
}
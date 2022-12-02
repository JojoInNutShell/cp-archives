#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> s1, s2, s3;
    int n, m, ss1,ss2,ss3, low;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> m;
        if(m == 1) {
            s1.push_back(i);
        } else if(m == 2) {
            s2.push_back(i);
        } else {
            s3.push_back(i);
        }
    }
    low = min(s1.size(), min(s2.size(), s3.size()));
    cout << low << endl;
    for(int i = 0; i < low; ++i) {
        cout << s1[i] << " " << s2[i] << " " << s3[i] << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define maxint 200;

using namespace std;

int min26(int n) {
    return min(n, 26 - n);
}

int mincmp(const string& s1, const string& s2, const int& len) {
    int minsum = 0;
    for(int i = 0; i < len; i++) {
        minsum += abs( min26(((int)s1[i] - (int)'a') - ((int)s2[i] - (int)'a')) );
    }
    return minsum;
}

int main()
{
    vector<string> arr;
    int T, n, m, lowestcmp, temp;
    string s;
    cin >> T;
    while(T--) {
        arr.clear();
        lowestcmp = maxint;
        cin >> n >> m;
        for(int i = 0; i < n; i++) { //Input
            cin >> s;
            arr.push_back(s);
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                temp = mincmp(arr[i], arr[j], m);
                if(temp < lowestcmp) {
                    lowestcmp = temp;
                }
            }
        }
        cout << lowestcmp << endl;
    }

    return 0;
}
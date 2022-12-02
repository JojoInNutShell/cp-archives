#include <bits/stdc++.h>

using namespace std;

array<pair<int, pair<int, string>>, 10006> coll;

int main()
{
    int T, D, Q, low, high, cp, datamatch;
    string maker, curmaker;
    cin >> T;
    while(T--) {
        cin >> D;
        for(int i = 0; i < D; i++) { //Database Input
            cin >> maker >> low >> high;
            auto temp = make_pair(high, maker);
            coll[i] = make_pair(low, temp);
        }
        sort(coll.begin(), coll.begin() + D);
        cin >> Q;
        for(int i = 0; i < Q; i++) { //Query Input and Check
            cin >> cp;
            datamatch = 0;
            for(int j = 0; j < D; j++) { //Search through Database
                if((coll[j]).first <= cp && (coll[j]).second.first >= cp) {
                    curmaker = (coll[j]).second.second;
                    datamatch++;
                }
            }
            if(datamatch != 1) {
                cout << "UNDETERMINED";
            } else {
                cout << curmaker;
            }
            if(i + 1 != Q) {
                cout << endl;
            }
        }
        cout << endl;
        if(T != 0) {
            cout << endl;
        }
    }

    return 0;
}
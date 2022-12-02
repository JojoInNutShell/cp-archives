#include <iostream>

using namespace std;

int main()
{
    string s;
    int slen, num;
    bool notfound = true;
    cin >> s;
    slen = s.size();
    if(s == "0" || s == "8") {
        num = stoi(s);
        notfound = false;
    } else {
        for(int i = 0; i < slen && notfound; i++) {
            num = ((int)s[i] - (int)('0'));
                if(num % 8 == 0) {
                    notfound = false;
                } else {
                    continue;
                }
        }
        if(notfound) {
            for (int i = 0; i < slen && notfound; i++) {
                for(int j = i + 1; j < slen && notfound; j++) {
                    num = ((int)s[i] - (int)('0')) * 10 + ((int)s[j] - (int)('0'));
                    if(num % 8 == 0) {
                        notfound = false;
                    } else {
                        continue;
                    }
                }
            }
        }
        if(notfound) {
            for (int i = 0; i < slen && notfound; i++) {
                for(int j = i + 1; j < slen && notfound; j++) {
                    for(int k = j + 1; k < slen && notfound; k++) {
                        num = ((int)s[i] - (int)('0')) * 100 + ((int)s[j] - (int)('0')) * 10 + ((int)s[k] - (int)('0'));
                        if(num % 8 == 0) {
                            notfound = false;
                        } else {
                            continue;
                        }
                    }
                }
            } 
        }
    }
    if(notfound) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        cout << num;
    }

    return 0;
}
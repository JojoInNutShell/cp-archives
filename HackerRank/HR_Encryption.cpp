#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string encryption(string sa) {
    string s;
    for(auto ch : sa) {
        if(ch != ' ') s.push_back(ch);
    }
    int sz = (int)(s.size());
    int r = ceil(sqrt(sz)), c = floor(sqrt(sz));
    
    string ans;
    for(int i = 0; i < r; ++i) {
        for(int j = i; j < sz; j += r) {
            ans.push_back(s[j]);
        }
        if(i + 1 != r) ans.push_back(' ');
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = encryption(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

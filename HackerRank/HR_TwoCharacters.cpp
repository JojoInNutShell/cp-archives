#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternate' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int alternate(string s) {
    map<char, int> mc;
    int mx = 0;
    for(auto c : s) mc[c]++;
    for(auto i = mc.begin(); i != mc.end(); ++i) {
        for(auto j = next(i); j != mc.end(); ++j) {
            string tmp = "";
            for(auto c : s) {
                if(c == (*i).first || c == (*j).first) tmp.push_back(c);
            }
            bool valid = true;
            for(int i = 2; i < (int)(tmp.size()); ++i) {
                if(tmp[i] != tmp[i - 2]) {
                    valid = false;
                    break;
                }
            }
            if(valid) mx = max(mx, (int)(tmp.size()));
        }
    }
    return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

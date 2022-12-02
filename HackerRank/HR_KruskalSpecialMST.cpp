#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
vector<pair<int, pair<int, int>>> edgeList;
vector<int> par, renk;

int findSet(int u) {
    if(u != par[u]) {
        return par[u] = findSet(par[u]);
    } else return u;
}

bool isSameSet(int u, int v) {
    if(findSet(u) == findSet(v)) return true;
    else return false;
}

void unionSet(int u, int v) {
    u = findSet(u);
    v = findSet(v);
    if(u != v) {
        if(renk[u] < renk[v]) swap(u, v);
        par[v] = u;
        if(renk[u] == renk[v]) renk[u]++;
    }
}

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight) {
    renk.assign(g_nodes + 1, 0);
    par.clear();
    for(int i = 0; i <= g_nodes; ++i) par.push_back(i);
    
    for(int i = 0; i < (int)(g_to.size()); ++i) {
        edgeList.push_back({g_weight[i], {g_from[i], g_to[i]}});
    }
    sort(edgeList.begin(), edgeList.end());
    int ans = 0;
    for(auto p : edgeList) {
        if(!isSameSet(p.second.first, p.second.second)) {
            ans += p.first;
            unionSet(p.second.first, p.second.second);
        }
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        int g_from_temp = stoi(g_from_to_weight[0]);
        int g_to_temp = stoi(g_from_to_weight[1]);
        int g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);
    fout << res;
    // Write your code here.

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

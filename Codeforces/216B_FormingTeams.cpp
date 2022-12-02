#include <bits/stdc++.h>

using namespace std;

//DATA STRUCTURES SHORTCUT
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int starter;
vector<vi> adjList;
array<bool,105> visited;

void init() {
	adjList.reserve(106);
	return;
}

void addEdge(int u, int v) {
	adjList[u].push_back(v);
	adjList[v].push_back(u);
	return;
}

bool dfs(int u, int c = 1) {
	visited[u] = true;
	if(adjList[u].empty()) { //ISOLATED VERTEX
		return false;
	}
	for(auto v : adjList[u]) {
		if(visited[v] == false) {
			return dfs(v, ++c);
		} else {
			if(c > 2 && c % 2 == 1 && v == starter) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	init();
	ios_base::sync_with_stdio(0);cin.tie(nullptr);
	int n, m, p1, p2, c;
	c = 0;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> p1 >> p2;
		addEdge(p1, p2);
	}
	for(int i = 1; i <= n; ++i) {
		if(visited[i] == false) {
			starter = i;
			if(dfs(i) == true) {
				++c;
			}
		}
	}
	if((n - c) % 2 == 1) {
		cout << ++c;
	} else {
		cout << c;
	}
	
	
	return 0;
}
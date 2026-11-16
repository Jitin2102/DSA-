// Detecting cycle in directed graph using DFS
// approach : using three states of nodes
// 0 = not visited
// 1 = in progress
// 2 = fully processed
// check if a node is in progress and we visit it again then there is a cycle
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 1) return true;

        if (vis[v] == 0 && dfs(v)) return true;
    }
    vis[u] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && dfs(i)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

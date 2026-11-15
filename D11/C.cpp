// cycle in graph or not
// This code checks if there is a cycle in an undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;
bool dfs(int u, int par, vector<vector<int>>& adj, vector<int>& vis) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (dfs(v, u, adj, vis)) return true;
        } else if (v != par)
            return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) {
                cycle = true;
                break;
            }
        }
    }
    cout << (cycle ? "YES" : "NO") << '\n';
    return 0;
}

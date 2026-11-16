// Bipartite graph
//  Approach : BFS
//  a bipartite graph can be colored using only two colors such that no two
//  adjacent vertices have the same color.
// and it does not contain any odd length cycle.
#include <bits/stdc++.h>
using namespace std;

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
    vector<int> color(n + 1, -1);
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        if (!ok) break;
    }
    cout << (ok ? "YES" : "NO") << '\n';

    return 0;
}

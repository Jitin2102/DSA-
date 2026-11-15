// shortest path in unweighted graph
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
    int s, t;
    cin >> s >> t;
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty()) {
        int basim = q.front();
        q.pop();
        for (int eagle : adj[basim]) {
            if (dist[eagle] == -1) {
                dist[eagle] = dist[basim] + 1;
                q.push(eagle);
            }
        }
    }
    cout << dist[t] << '\n';
    return 0;
}

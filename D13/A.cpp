// Single Source Shortest Path (Dijkstra's Algorithm)
#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(int s, vector<vector<pair<int, int>>>& adj, int n) {
    const long long INF = LLONG_MAX;
    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<long long> dist = dijkstra(1, adj, n);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}

// bellman Ford algorithm
#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

vector<long long> bellman_ford(int s, vector<tuple<int, int, int>>& edges,
                               int n) {
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
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
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    vector<long long> dist = bellman_ford(1, edges, n);
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << -1 << " ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";
    return 0;
}

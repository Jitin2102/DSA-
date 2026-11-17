// 1. Every vertex must be reachable from every other vertex.
// 2. The total edge weight must be minimum.
// The resulting structure is called a Minimum Spanning Tree (MST).
// An MST contains exactly V - 1 edges.

// Krushkal Algo
// s1 - Sort all the edges in non -
//     decreasing order of their weight.
// s2 - Pick the smallest edge. Check if it forms a cycle with the spanning
// tree formed so far. If cycle is not formed, include this edge. Else,
// discard it. s3 - Repeat step 2 until there are (V-1) edges in the
// spanning tree.
// s4 -
//      To detect cycle,
//      we can use Disjoint Set Union(DSU)
//  data structure.
//  s5- The time complexity of Kruskal's algorithm is O(E log E) or O(E log V),
//  where E is the number of edges and V is the number of vertices in the graph.

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

vector<int> parent, sz;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (auto& e : edges) cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    long long ans = 0;
    int cnt = 0;
    for (auto e : edges) {
        if (unite(e.u, e.v)) {
            ans += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    if (cnt != n - 1)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << '\n';
    return 0;
}

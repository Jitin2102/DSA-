// Disjoint set union - a ds in graph algos
//  it has two main operations
//  1. find - to find the representative of a set
//  2. union - to merge two sets into one
//  usecases - connected components, cycle detection, kruskal's algo, etc.
// TC - O(alpha(n)) for each operation, where alpha is the inverse Ackermann
// function

#include <bits/stdc++.h>
using namespace std;
vector<int> parent, sz;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) parent[i] = i;
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1)
            unite(a, b);
        else
            cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
    }
    return 0;
}

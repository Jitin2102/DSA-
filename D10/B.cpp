// Invert a binary tree.
// At each node:
// 1. If node is - 1, return.
// 2. Swap its left and right children.
// 3. Recursively invert both children.
#include <bits/stdc++.h>
using namespace std;
vector<int> lft, rgt;
void dfs(int basim) {
    if (basim == -1) return;
    swap(lft[basim], rgt[basim]);
    dfs(lft[basim]);
    dfs(rgt[basim]);
}
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        if (lft[u] != -1) q.push(lft[u]);
        if (rgt[u] != -1) q.push(rgt[u]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    lft.assign(n + 1, -1);
    rgt.assign(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int u, l, r;
        cin >> u >> l >> r;
        lft[u] = l;
        rgt[u] = r;
    }
    dfs(1);
    bfs(1);
    cout << '\n';
    return 0;
}

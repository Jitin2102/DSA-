// level order traversal
#include <bits/stdc++.h>
using namespace std;
vector<int> lft, rgt;
void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int basim = q.front();
        q.pop();
        cout << basim << " ";
        if (lft[basim] != -1) q.push(lft[basim]);
        if (rgt[basim] != -1) q.push(rgt[basim]);
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
    bfs(1);
    cout << '\n';
    return 0;
}

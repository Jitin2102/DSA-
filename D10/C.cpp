// diameter of a binary tree
#include <bits/stdc++.h>
using namespace std;
vector<int> lft, rgt;
int ans = 0;
int dfs(int basim) {
    if (basim == -1) return 0;
    int eagle = dfs(lft[basim]);
    int blade = dfs(rgt[basim]);
    ans = max(ans, eagle + blade);
    return 1 + max(eagle, blade);
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
    cout << ans << '\n';
    return 0;
}

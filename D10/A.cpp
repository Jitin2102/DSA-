#include <bits/stdc++.h>
using namespace std;
vector<int> lft, rgt;
int dfs(int basim) {
    if (basim == -1) return 0;
    return 1 + max(dfs(lft[basim]), dfs(rgt[basim]));
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
    cout << dfs(1) << '\n';

    return 0;
}

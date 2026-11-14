// checking whether a given binary tree is a binary search tree or not
#include <bits/stdc++.h>
using namespace std;
vector<long long> val;
vector<int> lft, rgt;
bool dfs(int basim, long long low, long long high) {
    if (basim == -1) return true;
    if (val[basim] <= low || val[basim] >= high) return false;
    return dfs(lft[basim], low, val[basim]) &&
           dfs(rgt[basim], val[basim], high);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    val.resize(n + 1);
    lft.assign(n + 1, -1);
    rgt.assign(n + 1, -1);
    for (int i = 0; i < n; i++) {
        int u, l, r;
        long long x;
        cin >> u >> x >> l >> r;
        val[u] = x;
        lft[u] = l;
        rgt[u] = r;
    }
    cout << (dfs(1, LLONG_MIN, LLONG_MAX) ? "YES" : "NO") << '\n';
    return 0;
}

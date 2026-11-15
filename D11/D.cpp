// no of islands
// When we find an unvisited land cell:
// 1. Increase the island count.
// 2. Start DFS from that
// 3. Visit all connected land cells
// 4. Mark them visited so we don't count them again. 5. Continue scanning
// the grid.Each DFS completely explores one island.

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y) {
    stack<pair<int, int>> st;
    st.push({x, y});
    grid[x][y] = 0;
    while (!st.empty()) {
        auto [basim, eagle] = st.top();
        st.pop();
        for (int i = 0; i < 4; i++) {
            int nx = basim + dx[i];
            int ny = eagle + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                grid[nx][ny] = 0;
                st.push({nx, ny});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    grid.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}

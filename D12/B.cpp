// Topological Sort

// Approach1 : DFS
//  Visit a node.
//  Visit all its unvisited neighbours.
//  Once all neighbours are processed, push the current node into a stack.
//  Reverse the finishing order by popping the stack. -> O(V+E) time and O(V)
//  space excluding the input graph.

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> vis;
stack<int> st;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
    st.push(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

// Apprpoach2 : Kahn's algorithm
// Calculate indegree of every vertex.
// Push all vertices with indegree 0 into a queue.
// Remove one vertex and add it to the answer.
// Decrease the indegree of all its outgoing neighbours.
// If any neighbour's indegree becomes 0, push it into the queue.
// Repeat until the queue is empty. -> O(V+E) time and O(V) space excluding the
// input graph.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indeg[i] == 0) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0) q.push(v);
        }
    }
    if ((int)ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int x : ans) cout << x << " ";
    }
    return 0;
}

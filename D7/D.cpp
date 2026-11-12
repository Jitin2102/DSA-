#include <bits/stdc++.h>
using namespace std;
// backtracing along with pruning (either include or exclude)
bool solve(int i, long long sum, long long target, vector<long long>& a) {
    if (sum == target) return true;
    if (i > a.size() || sum > target) return false;
    if (solve(i + 1, sum + a[i], target, a)) return true;
    return solve(i + 1, sum, target, a);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long target;
        cin >> n >> target;
        vector<long long> a(n);
        for (auto& x : a) cin >> x;
        cout << (solve(0, 0, target, a) ? "YES" : "NO") << "\n";
    }
    return 0;
}

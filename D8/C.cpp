// Merge intervals
#include <bits/stdc++.h>
using namespace std;

// sort the intervals by starting point then merge overlaps
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<long long, long long>> a(n);
        for (auto& [l, r] : a) cin >> l >> r;
        sort(a.begin(), a.end());
        vector<pair<long long, long long>> ans;
        for (auto [l, r] : a) {
            if (ans.empty() || l > ans.back().second)
                ans.push_back({l, r});
            else
                ans.back().second = max(ans.back().second, r);
        }
        for (auto [l, r] : ans) cout << l << " " << r << "\n";
        return 0;
    }
}

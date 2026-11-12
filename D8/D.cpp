#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<long long, long long>> a(n);

        for (auto& [l, r] : a) cin >> l >> r;

        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x.second != y.second) return x.second < y.second;
            return x.first < y.first;
        });

        int selected = 0;
        long long lastEnd = LLONG_MIN;

        for (auto [l, r] : a) {
            if (l > lastEnd) {
                selected++;
                lastEnd = r;
            }
        }

        cout << n - selected << '\n';
    }

    return 0;
}

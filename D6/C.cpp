#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long x;
        cin >> n >> x;
        unordered_map<int, int> mp;
        int a1 = -1, a2 = -1;
        for (int i = 0; i < n; i++) {
            long long v;
            cin >> v;

            long long need = x - v;
            if (a1 == -1 && mp.count(need)) {
                a1 = mp[need] + 1;
                a2 = i + 1;
            }
            mp.emplace(v, i);
        }
        if (a1 == -1)
            cout << -1 << "\n";
        else
            cout << a1 << " " << a2 << "\n";
    }
    return 0;
}

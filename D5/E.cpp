// Place the Cows

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool canPlace(vector<int>& a, int c, int dist) {
    int placed = 1;
    int last = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (a[i] - last >= dist) {
            placed++;
            last = a[i];
        }
        if (placed >= c) return true;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        sort(a.begin(), a.end());
        int l = 0, r = a.back() - a.front();
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canPlace(a, c, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

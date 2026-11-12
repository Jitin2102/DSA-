// Find the target
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int& v : a) cin >> v;
        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (a[mid] == x) {
                ans = mid;
                break;
            } else if (a[mid] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        cout << ans << "\n";
    }
}

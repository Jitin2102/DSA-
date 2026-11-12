// Square root
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        long long l = 0, r = min(x, 1000000000LL);
        long long ans = 0;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (mid == 0 || mid <= x / mid) {
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

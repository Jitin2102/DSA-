// u r given n machines workloads . a machine processes at most k units per hour
// . each machine's workload must be processed in whole hours ,so processing pi
// unit  takes: ceil of pi / k .You have at most  h hours . find the minimum
// integer processing speed k that completes all workloads within h hours ;

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long h;
        cin >> n >> h;
        vector<long long> a(n);
        long long r = 0;
        for (auto& x : a) {
            cin >> x;
            r = max(r, x);
        }
        long long l = 1, ans = r;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long hours = 0;
            for (long long x : a) hours += (x + mid - 1) / mid;
            if (hours <= h) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << "\n";
    }
}

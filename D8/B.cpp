#include <bits/stdc++.h>
using namespace std;

// count pairs with difference k
//  i < j
//  a[j] - a[i] = k ,k > 0

// Approach 1 : check each pair and count  - > O(N2) time
//  Approach 2 : Sorting and two pointers  -> O(Nlog(N)) time
//  Approach using hashset -> O(N) time

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        unordered_set<long long> seen;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            if (seen.count(x - k)) ans++;
            seen.insert(x);
        }
        cout << ans << "\n";
    }
    return 0;
}

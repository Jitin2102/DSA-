// Finding the unique number
#include <bits/stdc++.h>
using namespace std;
// Approach 1 count freq of each element - > O(n2) time
// Approach 2 : use hashmap - > O(n) time + O(n) space
// Approach 3 XOR ->O(N) time
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int ans = 0;
        for (int x : a) ans ^= x;
        cout << ans << "\n";
    }
    return 0;
}

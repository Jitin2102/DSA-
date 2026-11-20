// House Robber
#include <bits/stdc++.h>
using namespace std;
// A thief wants to rob houses arranged in a row.
// Each house contains some amount of money.
// But there is one restriction:
// The thief cannot rob two adjacent houses.
// Given an array a[], find the maximum amount of money the thief can rob
// without robbing adjacent houses.
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n, 0);
    dp[0] = a[0];
    if (n > 1) {
        dp[1] = max(a[0], a[1]);
    }
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
    }
    cout << dp[n - 1] << "\n";
    return 0;
}
// space optimization
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long prev2 = 0, prev1 = a[0];
    for (int i = 1; i < n; i++) {
        long long curr = max(prev1, prev2 + a[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << "\n";
    return 0;
}

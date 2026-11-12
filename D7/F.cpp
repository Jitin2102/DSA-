// check whether a number is power of 2 or not
#include <bits/stdc++.h>
using namespace std;
// Approach 1 - repeated division -> O(N) time
// Approach 2 - powers of 2 has exactly one bit is 1
// Approach 3 - n > 0 and n&(n-1) = 0 for every power of 2
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n > 0 && (n & (n - 1)) == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

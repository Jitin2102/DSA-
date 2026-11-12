// sum of n natural numbers
#include <bits/stdc++.h>
using namespace std;

// Using Loops // O(n) approach
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         long long n;
//         cin >> n;
//         long long sum = 0;
//         for (long long i = 1; i <= n; i++) sum += i;
//         cout << sum << "\n";
//     }
//     return 0;
// }

// O(n) approach
// long long RecurrSum(long long n) {
//     if (n == 1)
//         return 1;
//     else
//         return n + RecurrSum(n - 1);
// }
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         long long n;
//         cin >> n;
//         long long sum = RecurrSum(n);
//         cout << sum << "\n";
//     }
// }

// O(1) approach (optimal approach)
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sum = n * (n + 1) / 2;
        cout << sum << "\n";
    }
    return 0;
}

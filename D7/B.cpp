// Power of a number
#include <bits/stdc++.h>
using namespace std;

// using loops
// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         long long b, e;
//         cin >> b >> e;
//         long long ans = 1;
//         for (int i = 1; i <= e; i++) ans *= b;
//         cout << ans << "\n";
//     }
//     return 0;
// }

// using simple  recursion  will take O(n) and O(n) stack space
// Binary Recursion O(log(n))

// long long Power(long long b, int n) {
//     if (n == 0) return 1;
//     long long half = Power(b, n / 2);
//     long long ans = half * half;

//     if (n % 2 == 0) return ans;
//     if (n % 2 == 1) return ans * b;
// }

// Binary Exponentiation O(log(n)) // not getting correct result
long long Power(long long b, long long n) {
    long long ans = 1;
    while (n > 0) {
        if (n & 1) ans *= b;
        ans *= b;
        n >>= 1;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long b, n;
        cin >> b >> n;
        cout << Power(b, n) << "\n";
    }
    return 0;
}

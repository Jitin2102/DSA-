// Maximum  no of activities u can perform

// errors
// F.cpp: In function 'int main()':
// F.cpp:13:20: error: expected unqualified-id before '{' token
//          for (auto& {s, e} : a) cin >> s >> e;
//                     ^
// F.cpp:13:21: error: 's' was not declared in this scope
//          for (auto& {s, e} : a) cin >> s >> e;
//                      ^
// F.cpp:13:24: error: 'e' was not declared in this scope
//          for (auto& {s, e} : a) cin >> s >> e;
//                         ^
// F.cpp:13:20: error: initializer in range-based 'for' loop
//          for (auto& {s, e} : a) cin >> s >> e;
//                     ^
// F.cpp:17:23: error: 'INT_MIN' was not declared in this scope
//          int lastEnd = INT_MIN;
//                        ^~~~~~~
// F.cpp:18:19: error: 's' was not declared in this scope
//          for (auto{s, e} : a) {
//                    ^
// F.cpp:18:22: error: 'e' was not declared in this scope
//          for (auto{s, e} : a) {
//                       ^
// F.cpp:25:5: error: expected primary-expression before '}' token
//      }
//      ^
// F.cpp:25:5: error: expected ')' before '}' token
// F.cpp:25:5: error: expected primary-expression before '}' token
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (auto& [s, e] : a) cin >> s >> e;
        sort(a.begin(), a.end(),
             [](auto& x, auto& y) { return x.second < y.second; });
        int ans = 0;
        int lastEnd = INT_MIN;
        for (auto [s, e] : a) {
            if (s >= lastEnd) {
                ans++;
                lastEnd = e;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

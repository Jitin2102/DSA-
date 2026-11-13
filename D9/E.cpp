// Next Greater Element
// Approach 1 : scan all elements to the right of the current element and find
// the first greater element. -> O(n^2) time complexity.
// approach 2 use stack to track nextgreater element till now  - > O(n) time and
// O(n) space complexity.
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}

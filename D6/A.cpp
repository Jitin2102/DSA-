#include <bits/stdc++.h>
// is it a duplicate?

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_set<int> st;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (st.count(x)) found = true;
            st.insert(x);
        }
        cout << (found ? "Yes" : "No") << "\n";
    }
    return 0;
}

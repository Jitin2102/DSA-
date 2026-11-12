// Most Frequent Element
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            freq[x]++;
        }
        int element = INT_MAX;
        int best = 0;
        for (auto& [x, count] : freq) {
            if (count > best || (count == best && x < element)) {
                best = count;
                element = x;
            }
        }
        cout << element << " " << best << "\n";
    }
    return 0;
}

// First element greater than or equal to x (binary search)
// if no such element exists print n
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int& v : a) cin >> v;
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << "\n";
    }
}

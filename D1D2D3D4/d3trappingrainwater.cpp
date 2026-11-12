#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// Trapping rainWater
class Solution {
   public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int water = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                lmax = max(lmax, height[l]);
                water += lmax - height[l];
                l++;
            } else {
                rmax = max(rmax, height[r]);
                water += rmax - height[r];
                r--;
            }
        }
        return water;
    }
};
int main() {
    Solution sol;
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = sol.trap(height);
    cout << "maximum trapped water is " << res << endl;
    return 0;
}

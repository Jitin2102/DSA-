#include <iostream>
#include <vector>
using namespace std;
// Container with most water
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int ans = 0;
        while (s < e) {
            int area = min(height[s], height[e]) * (e - s);
            ans = max(ans, area);
            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> heights = {1, 6, 2, 5, 4, 3, 7};
    int res = sol.maxArea(heights);
    cout << "Area of Container having most water is " << res << endl;
    return 0;
}

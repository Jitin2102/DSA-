#include <iostream>
#include <vector>
using namespace std;
// Binary Search :-Search in Rotated Array
class Solution {
   public:
    int searchInRotatedArray(vector<int> nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == target) return m;
            if (nums[s] <= target) {
                if (nums[s] <= target && target < nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            } else {
                if (nums[m] < target && target <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};
int main() {
    vector<int> nums = {8, 4, 5, 6, 7};
    int target = 8;
    Solution sol;
    int res = sol.searchInRotatedArray(nums, target);
    cout << res;
    return 0;
}

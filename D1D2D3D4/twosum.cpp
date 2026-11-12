#include <iostream>
#include <vector>
using namespace std;  // errors

class Solution {
   public:
    vector<int> twosumidx(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] + nums[i - 1] == target) return {i - 1, i};
        }
        return {-1, -1};
    }
};
int main() {
    vector<int> test = {2, 7, 11, 15};
    int target = 13;
    // int n, target;
    // cout << "Enter number of elements in test array and the target element:
    // \n"; cin >> n >> target; for (int i = 0; i < n; i++) cin >> test[i];
    Solution sol;
    vector<int> res = sol.twosumidx(test, target);
    cout << res[0] << " " << res[1];
    return 0;
}

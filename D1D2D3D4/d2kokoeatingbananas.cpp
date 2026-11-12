#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    int minimumEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long hrs = 0;
            for (int p : piles) hrs += (p + (long long)mid - 1) / mid;
            if (hrs <= h)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 6, 7, 11};
    int h = 8;
    int res = sol.minimumEatingSpeed(nums, h);
    cout << "minimum eating of koko is " << res << endl;
    return 0;
}

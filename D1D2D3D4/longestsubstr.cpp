// Longest Substring without repeating characters
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        int left = 0, ans = 0;

        for (int right = 0; right < s.size(); right++) {
            unsigned char ch = s[right];
            if (last[ch] >= left) left = last[ch] + 1;
            last[ch] = right;
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main() {
    string t = "abcabcbb";
    Solution sol;
    int ans = sol.lengthOfLongestSubstring(t);
    cout << ans;
    return 0;
}

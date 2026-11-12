#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> mp;

        for (string& s : strs) {
            array<int, 26> freq{};

            for (char c : s) freq[c - 'a']++;

            mp[freq].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& it : mp) ans.push_back(it.second);

        return ans;
    }
};
int main() {
    Solution sol;
    vector<string> strs = {"tea", "eat", "tab", "ate", "bat", "tan", "nat"};
    vector<vector<string>> res = sol.groupAnagrams(strs);
    for (auto& i : res) {
        for (int j = 0; j < i.size(); j++) cout << i[j] << " ";
        cout << "\n";
    }
    return 0;
}

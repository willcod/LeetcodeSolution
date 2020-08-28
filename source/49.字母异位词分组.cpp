/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string, vector<string>> hash;

    for (string s : strs) {
      string key = s;
      sort(key.begin(), key.end());
      hash[key].push_back(s);
    }

    for (auto e : hash) {
      result.push_back(e.second);
    }
    return result;
  }
};
// @lc code=end

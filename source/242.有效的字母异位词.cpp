/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    unordered_map<char, int> hash;
    for (auto c : s) {
      hash[c]++;
    }

    for (auto c : t) {
      hash[c]--;
      if (hash[c] < 0) return false;
    }

    return true;
  }
};
// @lc code=end

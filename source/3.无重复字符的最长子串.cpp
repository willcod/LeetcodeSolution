/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n < 2) return n;

    int left = 0;
    int right = 0;
    int maxlen = 0;

    unordered_set<char> charSet;
    while (right < n) {
      if (charSet.count(s[right]) == 0) {
        charSet.insert(s[right++]);
        maxlen = max(maxlen, right - left);
      } else {
        charSet.erase(s[left++]);
      }
    }
    return maxlen;
  }
};
// @lc code=end

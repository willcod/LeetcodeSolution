/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.length();
    if (n < 2) return s;

    int start = 0;
    int maxlen = 1;

    int mid = 0;
    while (mid < n) {
      int l = mid;
      int r = mid;
      while (r < n && s[r + 1] == s[r]) r++;
      mid = r + 1;

      while (r < n && l > 0 && s[r + 1] == s[l - 1]) {
        r++;
        l--;
      }

      int len = r - l + 1;
      if (len > maxlen) {
        maxlen = len;
        start = l;
      }
    }

    return s.substr(start, maxlen);
  }
};
// @lc code=end

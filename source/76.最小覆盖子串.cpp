/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    vector<int> remaining(128, 0);
    for (int i = 0; i < t.length(); i++) {
      remaining[t[i]]++;
    }

    int m = s.length();
    int required = t.length();
    int minlen = INT_MAX;
    int left = 0, right = 0, begin = 0;
    while (left <= m && right <= m) {
      if (required) {
        if (right == m) break;

        remaining[s[right]]--;
        if (remaining[s[right]] >= 0) required--;
        right++;
      } else {
        if (minlen > right - left) {
          minlen = right - left;
          begin = left;
        }

        remaining[s[left]]++;
        if (remaining[s[left]] > 0) required++;
        left++;
      }
    }

    return minlen == INT_MAX ? "" : s.substr(begin, minlen);
  }
};
// @lc code=end

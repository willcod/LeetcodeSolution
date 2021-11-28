/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber) {
      int a = (columnNumber - 1) % 26 + 1;
      ans += a - 1 + 'A';
      columnNumber = (columnNumber - a) / 26;
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end

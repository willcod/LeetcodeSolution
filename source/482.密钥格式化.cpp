/*
 * @lc app=leetcode.cn id=482 lang=cpp
 *
 * [482] 密钥格式化
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string res = "";

    for (int i = s.length() - 1; i >= 0; i--) {
      if (isalpha(s[i]) || isdigit(s[i])) {
        if (res.length() % (k + 1) == k) res += '-';
        res += toupper(s[i]);
      }
    }

    reverse(res.begin(), res.end());

    return res;
  }
};
// @lc code=end

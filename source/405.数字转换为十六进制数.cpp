/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  string toHex(int num) {
    if (num == 0) return "0";

    string hexStr = "";
    unsigned int n = num;
    int base = 16;
    int remaining = 0;
    while (n > 0) {
      remaining = n % base;
      if (remaining < 10) {
        hexStr += ('0' + remaining);
      } else {
        hexStr += ('a' + (remaining % 10));
      }

      n /= base;
    }

    reverse(hexStr.begin(), hexStr.end());
    return hexStr;
  }
};
// @lc code=end

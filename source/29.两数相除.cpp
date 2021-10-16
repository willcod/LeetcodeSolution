/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int divide(int dividend, int divisor) {
    long res = 0;
    long up = fabs(dividend);
    long down = fabs(divisor);

    while (up >= down) {
      long count = 1;
      long base = down;
      while (up > (base << 1)) {
        count <<= 1;
        base <<= 1;
      }

      res += count;
      up -= base;
    }
    res = (dividend < 0) ^ (divisor < 0) ? -res : res;
    return (res > INT_MAX || res < INT_MIN) ? INT_MAX : res;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
      if (num == 1) return true;
    long l = 1;
    long r = num / 2;

    while (l <= r) {
      long m = l + (r - l) / 2;
      if (m * m == num)
        return true;

      else if (m * m > num) {
        r= m-1;
      } else if (m * m < num) {
        l=m + 1;
      }
    }

    return false;
  }
};
// @lc code=end

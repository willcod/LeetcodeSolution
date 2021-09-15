/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    if (n == 0) return false;

    long m = 1;
    while (m <= n) {
      if (m == n) return true;
      m *= 3;
    }

    return false;
  }
};
// @lc code=end

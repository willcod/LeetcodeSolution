/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int sqrtsum(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }
  bool isHappy(int n) {
    int slow = n;
    int fast = sqrtsum(n);

    while (slow != fast) {
      slow = sqrtsum(slow);
      fast = sqrtsum(sqrtsum(fast));

      if (slow == 1) return true;
    }

    return slow == 1;
  }
};
// @lc code=end

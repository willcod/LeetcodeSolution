/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    int one = 1;
    int two = 2;
    int sum = 0;

    for (int i = 3; i <= n; i++) {
      sum = one + two;
      one = two;
      two = sum;
    }

    return sum;
  }
};
// @lc code=end
class Solution {
 public:
  int climbStairs(int n) {
    vector memo(n + 1, 0);
    return climb(n, memo);
  }

  int climb(int n, vector<int>& memo) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    if (memo[n]) return memo[n];

    int stairs = climb(n - 1, memo) + climb(n - 2, memo);
    return memo[n] = stairs;
  }
};
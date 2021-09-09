/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
    unordered_map<int, int> cache;
 public:
  int climbStairs(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;

    if (cache.count(n)) return cache[n];

    auto re = climbStairs(n - 1) + climbStairs(n - 2);
    cache[n] = re;
    return re;
  }
};
// @lc code=end

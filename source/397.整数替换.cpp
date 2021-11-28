/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  unordered_map<int, int> cache;
  int integerReplacement(int n) { return dfs(n); }

  int dfs(long n) {
    if (n == 1) return 0;
    if (cache.count(n)) return cache[n];

    int ans = n % 2 == 0 ? dfs(n / 2) : min(dfs(n + 1), dfs(n - 1));
    cache[n] = ans + 1;
    return ans + 1;
  }
};
// @lc code=end

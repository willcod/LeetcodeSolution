/*
 * @lc app=leetcode.cn id=629 lang=cpp
 *
 * [629] K个逆序对数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  const long mod = 1000000007;
  int kInversePairs(int n, int k) {
    int dp[2][1001] = {0};
    long x;
    int cur, pre;

    dp[1][0] = 1;

    for (int i = 2; i <= n; ++i) {
      cur = i & 1;
      pre = (i - 1) & 1;

      for (int j = 0; j <= k; ++j) {
        x = dp[pre][j];

        if (j > 0) x = (x + dp[cur][j - 1]) % mod;

        if (j >= i) x = (x + mod - dp[pre][j - i]) % mod;

        dp[cur][j] = x;
      }
    }

    return dp[n & 1][k];
  }
};
// @lc code=end

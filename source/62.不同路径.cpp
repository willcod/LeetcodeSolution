/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int uniquePaths(int m, int n) {
    vector grid(m, vector(n, 1));

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
      }
    }

    return grid[m - 1][n - 1];
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=598 lang=cpp
 *
 * [598] 范围求和 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    int min_row = m;
    int min_col = n;

    for (auto& v : ops) {
      min_row = min(min_row, v[0]);
      min_col = min(min_col, v[1]);
    }

    return min_row * min_col;
  }
};
// @lc code=end

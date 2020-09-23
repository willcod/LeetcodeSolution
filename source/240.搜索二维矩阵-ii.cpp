/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int n = matrix.size() - 1;
    int m = 0;

    while (n >= 0 && m <= matrix[0].size() - 1) {
      if (matrix[n][m] > target) {
        n--;
      } else if (matrix[n][m] < target) {
        m++;
      } else {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end

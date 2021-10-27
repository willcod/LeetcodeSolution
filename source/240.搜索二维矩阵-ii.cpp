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
    int rows = matrix.size() - 1;
    int cols = 0;

    while (rows >= 0 && cols < matrix[0].size()) {
      if (matrix[rows][cols] == target) {
        return true;
      } else if (matrix[rows][cols] > target) {
        rows--;
      } else {
        cols++;
      }
    }

    return false;
  }
};
// @lc code=end

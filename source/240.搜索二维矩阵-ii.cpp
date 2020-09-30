/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        
        int row = matrix.size() - 1;
        int col = 0;

        while(row >= 0 && col < matrix[0].size()) {
            if (matrix[row][col] == target) return true;

            if (matrix[row][col] < target) {
                col++;
            } else {
                row--;
            }
        }
        return false;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows / 2; i++) {
            swap(matrix[i], matrix[rows - 1 - i]);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = i; j < cols; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

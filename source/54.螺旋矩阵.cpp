/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> steps{cols, rows - 1};
        int d = 0;
        int row = 0, col = -1;
        while (steps[d % 2]) {
            for (int i = 0; i < steps[d % 2]; i++) {
                row += dirs[d][0];
                col += dirs[d][1];
                res.push_back(matrix[row][col]);
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return res;
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector mat(n, vector(m, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[j][i] = matrix[i][j];
            }
        }

        return mat;
    }
};
// @lc code=end

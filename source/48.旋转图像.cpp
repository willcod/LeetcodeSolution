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
        if (matrix.empty() || matrix[0].empty()) return;

        int n = matrix.size();

        for (int i = 0; i < n/2; i++) {
            swap(matrix[i], matrix[n-i-1]);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector f(rows, vector(cols, 0));
        int maxLen = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    f[i][j] = matrix[i][j] - '0';
                } else {
                    f[i][j] =
                        min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
                }
                maxLen = max(f[i][j], maxLen);
            }
        }

        return maxLen * maxLen;
    }
};
// @lc code=end

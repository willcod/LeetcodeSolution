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
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector f(m, vector(n, 0));

        int maxlen = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    f[i][j] = matrix[i][j] - '0';
                } else {
                    f[i][j] =
                        min({f[i - 1][j - 1], f[i - 1][j], f[i][j - 1]}) + 1;
                }
                maxlen = max(f[i][j], maxlen);
            }
        }

        return maxlen * maxlen;
    }
};
// @lc code=end

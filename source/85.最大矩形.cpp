/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();

        vector heights(n+1, vector(m+1, 0));
        vector f(n+1, vector(m+1, vector(n+1, 0)));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i-1][j-1] == '0') continue;

                heights[i][j] = heights[i-1][j] + 1;
                for (int k = 1; k <= heights[i][j]; k++) {
                    f[i][j][k] = f[i][j-1][k] + k;
                    ans = max(ans, f[i][j][k]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector f(n+1, vector(n+1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = min(f[i+1][j], f[i+1][j+1])+triangle[i][j];
            }
        }

        return f[0][0];
    }
};
// @lc code=end


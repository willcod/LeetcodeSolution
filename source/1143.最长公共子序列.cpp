/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        vector f(m + 1, vector(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = max({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]});
                }
            }
        }

        return f[m][n];
    }
};
// @lc code=end

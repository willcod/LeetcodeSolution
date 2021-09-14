/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();

        vector<vector<long>> f(m + 1, vector<long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            f[0][i] = 1;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i - 1] == s[j - 1]) {
                    f[i][j] = f[i][j - 1] + f[i - 1][j - 1];
                } else {
                    f[i][j] = f[i][j - 1];
                }
            }
        }
        return f[m][n];
    }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector f(m + 1, vector(n + 1, false));
        f[0][0] = true;

        for (int i = 1; i <= n; i++) {
            f[0][i] = f[0][i - 1] && p[i - 1] == '*';
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    f[i][j] = f[i][j - 1] || f[i - 1][j];
                }
            }
        }

        return f[m][n];
    }
};
// @lc code=end

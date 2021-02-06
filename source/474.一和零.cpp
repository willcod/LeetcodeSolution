/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector f(m + 1, vector(n + 1, 0));
        for (auto s : strs) {
            auto num1 = 0;
            auto num0 = 0;
            for (char c : s) {
                if (c == '1')
                    num1++;
                else
                    num0++;
            }
            for (int i = m; i >= num0; i--) {
                for (int j = n; j >= num1; j--) {
                    f[i][j] = max(f[i][j], f[i - num0][j - num1] + 1);
                }
            }
        }
        return f[m][n];
    }
};
// @lc code=end

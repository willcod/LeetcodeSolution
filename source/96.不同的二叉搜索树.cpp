/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector f(n+1, 0);
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                f[i] += f[j]*f[i-j-1];
            }
        }

        return f[n];
    }
};
// @lc code=end


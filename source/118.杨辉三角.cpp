/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                res.push_back({1});
                continue;
            }

            vector<int> level(i+1);
            level[0] =1;
            level[i] = 1;

            for (int j = 1; j < i; j++) {
                level[j] = res[i-1][j-1]+res[i-1][j];
            }
            res.push_back(level);
        }

        return res;
    }
};
// @lc code=end

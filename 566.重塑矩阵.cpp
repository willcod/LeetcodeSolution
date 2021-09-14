/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.empty() || nums[0].empty()) return nums;
        int m = nums.size();
        int n = nums[0].size();
        if (m * n != r * c) return nums;

        vector res(r, vector(c, 0));
        for (int i = 0; i < m * n; i++) {
            res[i / c][i % c] = nums[i / n][i % n];
        }
        return res;
    }
};
// @lc code=end

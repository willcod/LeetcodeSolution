/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2) return 0;

        int target = (sum + S) >> 1;
        vector f(target + 1, 0);
        f[0] = 1;
        for (int num : nums) {
            for (int i = target; i >= num; i--) {
                f[i] += f[i - num];
            }
        }
        return f[target];
    }
};
// @lc code=end

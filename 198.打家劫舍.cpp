/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector f(n, 0);
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }
        return f[n - 1];
    }
};
// @lc code=end

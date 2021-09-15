/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector f(n, 0);
        // first
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }

        int first = f[n - 2];

        // last
        f[0] = 0;
        f[1] = nums[1];
        for (int i = 2; i < n; i++) {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }

        int last = f[n - 1];

        return max(first, last);
    }
};
// @lc code=end

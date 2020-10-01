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
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        

        vector dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        //first
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int first = dp[n-2];

        //last
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int last = dp[n-1];

        return max(first, last);
    }
};
// @lc code=end


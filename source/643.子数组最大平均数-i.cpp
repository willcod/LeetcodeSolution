/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);

        int maxSum = sum;
        for (int i = k; i < n; i++) {
            sum = sum - nums[i - k] + nums[i];
            maxSum = max(maxSum, sum);
        }
        return static_cast<double>(maxSum) / k;
    }
};
// @lc code=end

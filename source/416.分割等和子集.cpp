/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;

        sum /= 2;
        vector f(sum + 1, 0);
        f[0] = true;

        for (int num : nums) {
            for (int i = sum; i >= 0; i--) {
                if (i >= num) {
                    f[i] = f[i] || f[i - num];
                }
            }
        }
        return f[sum];
    }
};
// @lc code=end

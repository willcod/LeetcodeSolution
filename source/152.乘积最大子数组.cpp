/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;

        int res = nums[0];

        for (int i = 1, imax = res, imin = res; i < n; i++) {
            if (nums[i] < 0) {
                swap(imin, imax);
            }

            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            res = max(imax, res);
        }

        return res;
    }
};
// @lc code=end

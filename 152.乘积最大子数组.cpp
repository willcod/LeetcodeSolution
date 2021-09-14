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
        if (nums.empty()) return 0;
        int n = nums.size();

        int res = nums[0];
        int imax = nums[0];
        int imin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(imax, imin);

            imax = max(nums[i], nums[i] * imax);
            imin = min(nums[i], nums[i] * imin);

            res = max(res, imax);
        }
        return res;
    }
};
// @lc code=end

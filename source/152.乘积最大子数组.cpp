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
        int Max = nums[0];
        int Min = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0) swap(Max, Min);

            Max = max(Max * nums[i], nums[i]);
            Min = min(Min * nums[i], nums[i]);

            res = max(res, Max);
        }

        return res;
    }
};
// @lc code=end

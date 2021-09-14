/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);

        int left = 1, right = 1;
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            res[i] *= left;
            res[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }

        return res;
    }
};
// @lc code=end

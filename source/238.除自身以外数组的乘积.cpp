/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> res(nums.size(), 1);
        int left = 1;
        int right = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--) {
            res[i] *= left;
            res[j] *= right;
            left *= nums[i];
            right *= nums[j];
        }
        return res;
    }
};
// @lc code=end

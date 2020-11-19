/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int f = nums[0];
    int res = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      f = max(f + nums[i], nums[i]);
      res = max(res, f);
    }
    return res;
  }
};
// @lc code=end

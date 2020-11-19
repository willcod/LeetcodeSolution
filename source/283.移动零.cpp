/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i]) nums[j++] = nums[i];
    }

    for (; j < nums.size(); j++) {
      nums[j] = 0;
    }
  }
};
// @lc code=end

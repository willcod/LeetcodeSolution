/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2) return nums.size();

    int index = 2;
    for (int i = 2; i < nums.size(); i++) {
      if (nums[i] != nums[index - 2]) {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int rightmost = 0;

    for (int i = 0; i <= rightmost; i++) {
      rightmost = max(rightmost, nums[i] + i);
      if (rightmost >= nums.size() - 1) return true;
    }

    return false;
  }
};
// @lc code=end

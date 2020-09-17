/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int count = 0;
    int end = 0;
    int rightmost = 0;

    for (int i = 0; i < nums.size() - 1; i++) {
      rightmost = max(rightmost, i + nums[i]);
      if (i == end) {
        end = rightmost;
        count++;
      }
    }
    return count;
  }
};
// @lc code=end

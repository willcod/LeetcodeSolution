/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int m = l + (r - l) / 2;

      if (nums[m] > nums[m + 1]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
// @lc code=end

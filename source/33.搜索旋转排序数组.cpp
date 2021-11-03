/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (nums[m] == target) return m;

      if (nums[m] >= nums[l]) {
        if (target >= nums[l] && target < nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else {
        if (target <= nums[r] && target > nums[m]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }

    return -1;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (target == nums[m]) return true;

      if (nums[m] == nums[l])
        l++;
      else if (nums[m] > nums[l]) {
        if (target < nums[m] && target >= nums[l]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else {
        if (target > nums[m] && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }

    return false;
  }
};
// @lc code=end

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
    if (nums.empty()) return -1;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target) return i;
    }
    return -1;
  }
};
// @lc code=end
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) return -1;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        return mid;
      }

      if (nums[mid] >= nums[left]) {
        if (target >= nums[left] && target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else {
        if (target > nums[mid] && target <= nums[right]) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return -1;
  }
};

/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int result = 0;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
      result = max(result, min(height[l], height[r]) * (r - l));

      if (height[l] < height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return result;
  }
};
// @lc code=end

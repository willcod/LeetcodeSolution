/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    if (n < 3) return false;

    int small = INT_MAX;
    int middle = INT_MAX;

    for (auto num : nums) {
      if (num <= small) {
        small = num;
      } else if (num <= middle) {
        middle = num;
      } else if (num > middle) {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end

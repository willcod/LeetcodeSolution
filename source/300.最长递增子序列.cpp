/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector f(nums.size(), 1);

    int maxLen = 1;

    for (int i = 1; i < nums.size(); i++)
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          f[i] = max(f[i], f[j] + 1);
          maxLen = max(maxLen, f[i]);
        }
      }

    return maxLen;
  }
};
// @lc code=end

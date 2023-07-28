/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int max_len = 1;

    int len = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        len++;
        max_len = max(max_len, len);
      } else {
        len = 1;
      }
    }

    return max_len;
  }
};
// @lc code=end

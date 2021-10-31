/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> res;
    if (nums[0] != nums[1]) res.push_back(nums[0]);
    if (n >= 2 && nums[n - 1] != nums[n - 2]) res.push_back(nums[n - 1]);

    for (int i = 1; i < nums.size() - 1; i++) {
      if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
        res.push_back(nums[i]);
      }
    }

    return res;
  }
};
// @lc code=end

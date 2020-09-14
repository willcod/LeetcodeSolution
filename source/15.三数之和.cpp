/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      int f = i + 1;
      int b = nums.size() - 1;

      while (f < b) {
        int sum = nums[i] + nums[f] + nums[b];
        if (sum == 0) {
          res.push_back({nums[i], nums[f], nums[b]});
          while (f < b && nums[f] == nums[f + 1]) f++;
          while (f < b && nums[b] == nums[b - 1]) b--;
          f++;
          b--;
        } else if (sum > 0)
          b--;
        else
          f++;
      }
      while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
    }
    return res;
  }
};
// @lc code=end

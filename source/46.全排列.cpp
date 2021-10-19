/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> sub;
    vector<bool> used(nums.size(), false);
    permute(res, sub, nums, used);
    return res;
  }

  void permute(vector<vector<int>>& res, vector<int>& sub, vector<int>& nums,
               vector<bool>& used) {
    if (sub.size() == nums.size()) {
      res.push_back(sub);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        sub.push_back(nums[i]);
        used[i] = true;
        permute(res, sub, nums, used);
        used[i] = false;
        sub.pop_back();
      }
    }
  }
};
// @lc code=end

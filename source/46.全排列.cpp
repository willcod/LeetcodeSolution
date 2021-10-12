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
    vector<int> per;
    vector<bool> used(nums.size(), false);

    permute(res, per, nums, used);
    return res;
  }

  void permute(vector<vector<int>>& res, vector<int>& per, vector<int>& nums,
               vector<bool>& used) {
    if (per.size() == nums.size()) {
      res.push_back(per);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        per.push_back(nums[i]);
        used[i] = true;
        permute(res, per, nums, used);
        used[i] = false;
        per.pop_back();
      }
    }
  }
};
// @lc code=end

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
    vector<int> path;
    vector<bool> used(nums.size(), false);

    permute(res, path, nums, used);
    return res;
  }

  void permute(vector<vector<int>>& res, vector<int>& path, vector<int>& nums,
               vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i] == false) {
        path.push_back(nums[i]);
        used[i] = true;
        permute(res, path, nums, used);
        path.pop_back();
        used[i] = false;
      }
    }
  }
};
// @lc code=end

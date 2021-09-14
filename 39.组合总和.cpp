/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    combinationSum(res, path, candidates, target, 0);
    return res;
  }

  void combinationSum(vector<vector<int>>& res, vector<int>& path,
                      vector<int>& nums, int target, int index) {
    if (path.size() > 0 && target == 0) {
      res.push_back(path);
    }

    // if (index == nums.size() - 1) return;

    for (int i = index; i < nums.size(); i++) {
      if (nums[i] > target) break;
      path.push_back(nums[i]);
      combinationSum(res, path, nums, target - nums[i], i);
      path.pop_back();
    }
  }
};
// @lc code=end

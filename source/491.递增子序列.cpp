/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include "cpp_includes.h"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    findSubsequence(res, nums, path, 0);
    return res;
  }

  void findSubsequence(vector<vector<int>>& res, vector<int>& nums,
                       vector<int>& path, int index) {
    if (path.size() > 1) {
      res.push_back(path);
    }

    int used[201] = {0, 0};
    for (int i = index; i < nums.size(); i++) {
      if (path.empty() || nums[i] >= path.back()) {
        if (used[nums[i] + 100] == 0) {
          path.push_back(nums[i]);
          findSubsequence(res, nums, path, i + 1);
          path.pop_back();
          used[nums[i] + 100] = 1;
        }
      }
    }
  }
};
// @lc code=end

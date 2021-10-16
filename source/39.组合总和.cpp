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
    vector<vector<int>> res;
    vector<int> sub;
    sort(candidates.begin(), candidates.end());
    combination(res, sub, target, candidates, 0);
    return res;
  }

  void combination(vector<vector<int>>& res, vector<int>& sub, int remain,
                   vector<int>& candidates, int index) {
    if (index >= candidates.size()) return;

    if (remain == 0) {
      res.push_back(sub);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
        if (remain < candidates[i]) break;
        sub.push_back(candidates[i]);
        combination(res, sub, remain-candidates[i], candidates, i);
        sub.pop_back();
    }
  }
};
// @lc code=end

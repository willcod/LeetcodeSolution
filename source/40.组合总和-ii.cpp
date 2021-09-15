/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    if (candidates[0] > target) return {};

    vector<vector<int>> res;
    vector<int> path;

    backtracking(res, path, candidates, target, 0);
    return res;
  }

  void backtracking(vector<vector<int>>& res, vector<int>& path,
                    vector<int>& candidates, int target, int index) {
    if (target == 0 && path.size() > 0) {
      res.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (candidates[i] > target) break;

      // 同一层相同数值的结点，从第 2 个开始，候选数更少，结果一定发生重复，因此跳过
      if (i > index && candidates[i] == candidates[i - 1]) continue;

      path.push_back(candidates[i]);
      backtracking(res, path, candidates, target - candidates[i], i + 1);
      path.pop_back();
    }
  }
};
// @lc code=end

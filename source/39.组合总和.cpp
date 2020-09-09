/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
  }
};
// @lc code=end
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    backtracking(res, candidates, target, path, 0);
    return res;
  }

  void backtracking(vector<vector<int>>& res, vector<int>& candidates,
                    int target, vector<int>& path, int index) {
    if (!target) {
      res.push_back(path);
      return;
    }

    for (int i = index; i < candidates.size(); i++) {
      if (target < candidates[i]) break;

      path.push_back(candidates[i]);
      backtracking(res, candidates, target - candidates[i], path, i);
      path.pop_back();
    }
  }
};
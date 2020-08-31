/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
  vector<vector<int>> results;

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<bool> used(nums.size(), false);
    vector<int> sub;
    sort(nums.begin(), nums.end());
    backtracking(nums, used, sub, 0);
    return results;
  }

  void backtracking(vector<int>& nums, vector<bool>& used, vector<int>& sub,
                    int pos) {
    if (pos == nums.size()) {
      results.push_back(sub);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;
      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

      sub.push_back(nums[i]);
      used[i] = true;
      backtracking(nums, used, sub, pos + 1);
      sub.pop_back();
      used[i] = false;
    }
  }
};
// @lc code=end
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> results;
    getPermuteUnique(results, nums, 0, nums.size() - 1);
    return results;
  }

  void getPermuteUnique(vector<vector<int>>& results, vector<int>& nums,
                        int start, int end) {
    if (start == end) {
      results.push_back(nums);
      return;
    }

    unordered_set<int> set;
    for (int i = start; i <= end; i++) {
      if (set.count(nums[i]) == 1) continue;
      set.insert(nums[i]);
      swap(nums[i], nums[start]);
      getPermuteUnique(results, nums, start + 1, end);
      swap(nums[i], nums[start]);
    }
  }
};